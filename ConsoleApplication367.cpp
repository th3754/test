

#include <iostream>
#include <vector>
#include <algorithm>
#include "curve.h"

using namespace std;

struct pred
{
    bool operator()(const circle* p1, const circle* p2)
    {
        return p1->get_r() < p2->get_r();
    }
};

int main()
{
    vector<curve*> v_cur;

    for (int i = 0; i < 100; ++i)
    {
        switch (rand() % 3)
        {
            case 0: v_cur.push_back(new circle( rand() % 100, rand() % 100, rand() % 50)); break;
            case 1: v_cur.push_back(new ellipse(rand() % 100, rand() % 100, rand() % 50, rand() % 50)); break;
            case 2: v_cur.push_back(new helix(  rand() % 100, rand() % 100, rand() % 50, rand() % 50, rand() % 50)); break;
        }
    }

    /*
     for (int i = 0; i < 10; ++i)
    {
        cout << v_cur[i]->get_point( 3.14f / 4) << endl;
        cout << v_cur[i]->derivative(3.14f / 4) << endl;
        cout << endl;
    }
    */
   

    vector<circle*> v_p_circle;

    for (int i = 0; i < 100; ++i)
    {
        if (circle* p = dynamic_cast<circle*>(v_cur[i]))
        {
            v_p_circle.push_back(p);
        }
    }

    for (int i = 0; i < v_p_circle.size(); ++i) cout << v_p_circle[i]->get_r() << " "; cout << endl;

    std::sort(v_p_circle.begin(), v_p_circle.end(), pred());

    for (int i = 0; i < v_p_circle.size(); ++i) cout << v_p_circle[i]->get_r() << " "; cout << endl;




    float sum_r = 0;
    for (int i = 0; i < v_p_circle.size(); ++i) sum_r += v_p_circle[i]->get_r();

    cout << "sum = " << sum_r << endl;




    for (int i = 0; i < 10; ++i) delete v_cur[i];
}

