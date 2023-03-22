#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct SemiZone
{
    int l, r;
    int64_t area;

    SemiZone(){}
    SemiZone(int l, int r, int64_t area) : l(l), r(r), area(area) {}
};

struct Event
{
    virtual int getPos() const = 0;
    virtual int getOrder() const = 0;
};

struct RectEvent : public Event
{
    virtual void execute(int &balance, multiset <int> &heights, vector <SemiZone> &semizones,
                         int64_t &currZoneArea, int &startPos, int &lastPos) = 0;
};

struct RectStartEvent : public RectEvent
{
    int h;
    int pos;

    RectStartEvent(int pos, int h) : pos(pos), h(h) {}

    int getPos() const override
    {
        return pos;
    }

    int getOrder() const override
    {
        return 1;
    }

    void execute(int &balance, multiset <int> &heights, vector <SemiZone> &semizones,
                         int64_t &currZoneArea, int &startPos, int &lastPos) override
    {
        balance++;

        if (balance == 1)
        {
            startPos = pos;
            currZoneArea = 0;
        }
        else
        {
            currZoneArea += (pos - lastPos) * (*prev(heights.end()) - *heights.begin());
        }

        lastPos = pos;
        heights.insert(h);
    }
};

struct RectEndEvent : public RectEvent
{
    int h;
    int pos;

    RectEndEvent(int pos, int h) : pos(pos), h(h) {}

    int getPos() const override
    {
        return pos;
    }

    int getOrder() const override
    {
        return 2;
    }

    void execute(int &balance, multiset <int> &heights, vector <SemiZone> &semizones,
                 int64_t &currZoneArea, int &startPos, int &lastPos) override
    {
        balance--;
        currZoneArea += (pos - lastPos) * (*prev(heights.end()) - *heights.begin());

        if (balance == 0)
        {
            semizones.emplace_back(startPos, pos, currZoneArea);
        }

        lastPos = pos;
        heights.erase(heights.find(h));
    }
};

struct ZoneEvent : public Event
{
    virtual void execute(int &balance, int &zonesCnt, int64_t &zoneArea, int64_t &maxZoneArea, int64_t &allZonesArea) = 0;
};

struct ZoneStartEvent : public ZoneEvent
{
    int pos;
    int64_t area;

    ZoneStartEvent(int pos, int64_t area) : pos(pos), area(area) {}

    int getPos() const override
    {
        return pos;
    }

    int getOrder() const override
    {
        return 2;
    }

    void execute(int &balance, int &zonesCnt, int64_t &zoneArea, int64_t &maxZoneArea, int64_t &allZonesArea) override
    {
        balance++;
        if (balance == 1)
        {
            zoneArea = 0;
            zonesCnt++;
        }

        zoneArea += area;
    }
};

struct ZoneEndEvent : public ZoneEvent
{
    int pos;
    int64_t area;

    ZoneEndEvent(int pos, int64_t area) : pos(pos), area(area) {}

    int getPos() const override
    {
        return pos;
    }

    int getOrder() const override
    {
        return 1;
    }

    void execute(int &balance, int &zonesCnt, int64_t &zoneArea, int64_t &maxZoneArea, int64_t &allZonesArea) override
    {
        balance--;

        if (balance == 0)
        {
            maxZoneArea = max(maxZoneArea, zoneArea);
            allZonesArea += zoneArea;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector <RectEvent*> rectEventsPositive;
    vector <RectEvent*> rectEventsNegative;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int h;
        if (max(y1, y2) > 0)
        {
            h = max(y1, y2);
        }
        else
        {
            h = min(y1, y2);
        }

        if (h > 0)
        {
            rectEventsPositive.push_back(new RectStartEvent(min(x1, x2), h));
            rectEventsPositive.push_back(new RectEndEvent(max(x1, x2), h));
        }
        else
        {
            rectEventsNegative.push_back(new RectStartEvent(min(x1, x2), h));
            rectEventsNegative.push_back(new RectEndEvent(max(x1, x2), h));
        }
    }

    vector <SemiZone> semizones;

    int lastPos = -1, startPos = -1;
    multiset <int> heights = {0};
    int balance = 0;
    int64_t currZoneArea = 0;
    sort(rectEventsPositive.begin(), rectEventsPositive.end(),
    [](const RectEvent* A, const RectEvent* B)
    {
        if (A->getPos() != B->getPos())
        {
            return A->getPos() < B->getPos();
        }

        return A->getOrder() < B->getOrder();
    });
    for (RectEvent *e : rectEventsPositive)
    {
        e->execute(balance, heights, semizones, currZoneArea, startPos, lastPos);
    }

    lastPos = -1;
    startPos = -1;
    heights = {0};
    balance = 0;
    currZoneArea = 0;
    sort(rectEventsNegative.begin(), rectEventsNegative.end(),
    [](const RectEvent* A, const RectEvent* B)
    {
        if (A->getPos() != B->getPos())
        {
            return A->getPos() < B->getPos();
        }

        return A->getOrder() < B->getOrder();
    });
    for (RectEvent *e : rectEventsNegative)
    {
        e->execute(balance, heights, semizones, currZoneArea, startPos, lastPos);
    }

    vector <ZoneEvent*> zoneEvents;
    for (const SemiZone &sz : semizones)
    {
        zoneEvents.push_back(new ZoneStartEvent(sz.l, sz.area));
        zoneEvents.push_back(new ZoneEndEvent(sz.r, sz.area));
    }

    sort(zoneEvents.begin(), zoneEvents.end(),
    [](const ZoneEvent* A, const ZoneEvent* B)
    {
        if (A->getPos() != B->getPos())
        {
            return A->getPos() < B->getPos();
        }

        return A->getOrder() < B->getOrder();
    });

    balance = 0;
    int zonesCnt = 0;
    int64_t zoneArea = 0, maxZoneArea = 0, allZonesArea = 0;

    for (ZoneEvent *e : zoneEvents)
    {
        e->execute(balance, zonesCnt, zoneArea, maxZoneArea, allZonesArea);
    }

    cout << zonesCnt << '\n' << allZonesArea << '\n' << maxZoneArea << '\n';
}
