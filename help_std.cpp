
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class Problem
{
public:
    string name;
    int in_contest_num;
    vector<int> contest_id_set;
    bool operator==(const Problem& p_1){
        return p_1.name == this->name;
    }

    Problem()
    {
        in_contest_num = 0;
        vector<int> c;
        contest_id_set = c;
    }
};

class Contest
{
public:
    int id;
    bool is_over;
    vector<string> problem_name_set;
    bool operator==(const Contest& c_1){
        return c_1.id == this->id;
    }
    Contest()
    {
        is_over = false;
        vector<string> s;
        problem_name_set = s;
    }
};

int main()
{
    freopen("1.in", "r", stdin);
    vector<Problem> problem_set;
    vector<Contest> contest_set;

    int n, q;

    cin >> n >> q;

    for(int i = 0; i < n; i++){
        Problem p;
        string p_name;
        cin >> p_name;
        p.name = p_name;
        problem_set.push_back(p);
    }

    for(int i = 0; i < q; i++){
        int op_type;
        cin >> op_type;
        if(op_type == 1){
            Problem p;
            string p_name;
            cin >> p_name;
            p.name = p_name;
            auto p_pointer = find(problem_set.begin(), problem_set.end(), p);
            auto what_ever = *p_pointer;
            if((p_pointer != problem_set.end()) && ((*p_pointer).in_contest_num > 0)){
                sort((*p_pointer).contest_id_set.begin(), (*p_pointer).contest_id_set.end());
                auto i = (*p_pointer).contest_id_set.begin();
                cout << *i;
                for(auto i = (*p_pointer).contest_id_set.begin() + 1;
                        i < (*p_pointer).contest_id_set.end(); i++){
                        cout << " " << *i;
                }
                cout << endl;
            } else {
                cout << "DoNotExist" << endl;
            }
        }
        if(op_type == 2){
            Problem p;
            string p_name;
            cin >> p_name;
            p.name = p_name;
            auto p_pointer = find(problem_set.begin(), problem_set.end(), p);
            if((p_pointer != problem_set.end()) && (*p_pointer).in_contest_num == 0){
                cout << "Response" << endl;
            } else {
                cout << "DoNotExist" << endl;
            }
        }
        if(op_type == 3){
            Contest c;
            c.id = contest_set.size() + 1;
            contest_set.push_back(c);
        }
        if(op_type == 4){
            int c_id;
            cin >> c_id;
            Contest c;
            c.id = c_id;
            auto c_pointer = find(contest_set.begin(), contest_set.end(), c);
            if((c_pointer != contest_set.end()) && !((*c_pointer).is_over)){
                (*c_pointer).is_over = true;
                for(auto i = (*c_pointer).problem_name_set.begin();
                        i < (*c_pointer).problem_name_set.end(); i++){
                    Problem p;
                    p.name = *i;
                    auto p_pointer = find(problem_set.begin(), problem_set.end(), p);
                    (*p_pointer).in_contest_num--;
                    for(auto j = (*p_pointer).contest_id_set.begin(); j < (*p_pointer).contest_id_set.end();){
                        if(*j == c.id){
                            j = (*p_pointer).contest_id_set.erase(j);
                        } else {
                            j++;
                        }
                    }
                }
            } else {
                cout << "Invalid" << endl;
            }
        }
        if(op_type == 5){
            string p_name;
            int c_id;
            cin >> p_name >> c_id;
            Problem p;
            p.name = p_name;
            Contest c;
            c.id = c_id;

            auto c_pointer = find(contest_set.begin(), contest_set.end(), c);

            if((c_pointer != contest_set.end()) && !((*c_pointer).is_over)){
                auto p_pointer = find(problem_set.begin(), problem_set.end(), p);
                if(p_pointer != problem_set.end()){
                    //有题
                    auto what_ever = *p_pointer;
                    (*p_pointer).in_contest_num++;
                    (*c_pointer).problem_name_set.push_back(p.name);
                    (*p_pointer).contest_id_set.push_back(c.id);
                } else {
                    //加新题
                    p.contest_id_set.push_back(c.id);
                    p.in_contest_num++;
                    problem_set.push_back(p);
                    (*c_pointer).problem_name_set.push_back(p.name);
                }
            } else {
                cout << "Invalid" << endl;
            }

        }
    }

    return 0;
}
