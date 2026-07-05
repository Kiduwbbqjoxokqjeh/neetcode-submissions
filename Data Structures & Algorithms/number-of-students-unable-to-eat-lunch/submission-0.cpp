class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int n1 = students.size(),n2 = sandwiches.size();
        while(!students.empty() and !sandwiches.empty())
        {
            if(students[0] == sandwiches[0])
            {
                auto it1 = students.begin();
                auto it2 = sandwiches.begin();
                students.erase(it1); sandwiches.erase(it2);
            }
            else
            {
                auto it = find(students.begin(),students.end(),sandwiches[0]);
                if(it == students.end()) return students.size();
                int idx = it-students.begin();
                rotate(students.begin(),students.begin()+idx,students.end());
            }
        }
        if(!students.empty()) return students.size();
        
    }
};