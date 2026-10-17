class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char,int>have;

        for(int i = 0; i<text.size(); i++)
        {
            have[text[i]]++;

        }

        unordered_map<char, int>need;

        need['b'] = 1;
          need['a'] = 1;
            need['l'] = 2;
              need['o'] = 2;
                need['n'] = 1;

                int ans  = INT_MAX;

                for(auto i : need)
                {
                    char c = i.first;

                    int fneed = i.second;
                    int fhave = have[c];

                    int times = fhave/fneed;

                    ans = min( ans , times);
                }
                return ans;
        
    }
};