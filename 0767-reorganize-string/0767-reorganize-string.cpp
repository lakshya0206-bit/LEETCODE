
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto i : freq) {
            pq.push({i.second, i.first});
        }

        string res = "";

        while (pq.size() > 1) {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            res.push_back(first.second);
            res.push_back(second.second);

            first.first--;
            second.first--;

            if (first.first > 0) {
                pq.push(first);
            }

            if (second.first > 0) {
                pq.push(second);
            }
        }

        if (!pq.empty()) {
            auto last = pq.top();
            pq.pop();

            if (last.first > 1) {
                return "";
            }

            res.push_back(last.second);
        }

        return res;
    }
};

