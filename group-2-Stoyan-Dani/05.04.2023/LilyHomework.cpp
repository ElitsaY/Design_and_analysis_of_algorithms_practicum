#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void encodeAsPermutation(vector<int> &arr)
{
    vector<int> sortedCopy = arr;
    sort(sortedCopy.begin(), sortedCopy.end());

    for (int &x : arr)
    {
        x = lower_bound(sortedCopy.begin(), sortedCopy.end(), x) - sortedCopy.begin();
    }
}

int evalPermutation(const vector <int> &arr)
{
    int n = arr.size();
    vector<bool> used(arr.size(), false);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            int x = i;
            int cycleSz = 0;

            do
            {
                cycleSz++;
                used[x] = true;

                x = arr[x];
            }
            while (x != i);

            ans += cycleSz - 1;
        }
    }

    return ans;
}

int lilysHomework(vector<int> arr)
{
    encodeAsPermutation(arr);
    int ans = evalPermutation(arr);

    for (int &x : arr)
    {
        x = arr.size() - 1 - x;
    }
    ans = min(ans, evalPermutation(arr));

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

