class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),compare);
        int currTime=0;
        priority_queue<int> courseQ;
        for(int i=0;i<courses.size();i++){
            courseQ.push(courses[i][0]);
            currTime+=courses[i][0];
            if(currTime>courses[i][1]){
                currTime-=courseQ.top();
                courseQ.pop();
            }
        }
        return courseQ.size();
    }
};