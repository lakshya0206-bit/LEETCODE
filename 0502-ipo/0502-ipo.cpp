
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();

        vector<pair<int, int>> prog;

        for (int i = 0; i < n; i++) {
            prog.push_back({capital[i], profits[i]});
        }

        sort(prog.begin(), prog.end());

        int idx = 0;

        priority_queue<int> pq;

        while (k--) {

            while (idx < n) {

                if (prog[idx].first > w)
                    break;

                pq.push(prog[idx].second);

                idx++;
            }

            if (pq.empty())
                break;

            w = w + pq.top();

            pq.pop();
        }

        return w;
    }
};
