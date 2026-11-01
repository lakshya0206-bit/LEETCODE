
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(),
        [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<int> pq;

        int totalTime = 0;

        for (int i = 0; i < courses.size(); i++) {

            int duration = courses[i][0];
            int lastDay = courses[i][1];

            totalTime += duration;
            pq.push(duration);

            if (totalTime > lastDay) {
                totalTime -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};

