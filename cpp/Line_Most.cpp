#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<functional>
#include <queue>
#include<stack>
#include<string>



using namespace std;


set<size_t> s;

  struct Point {
 
       int x;

        int y;
 
          Point() : x(0), y(0) {}
 
         Point(int a, int b) : x(a), y(b) {}

 };

    struct Line{

        Point s,e;

        int k,b;

        Line(Point x, Point y):s(x),e(y){

            if(s.x==e.x)

                k=0;

            else

                k=(s.y-e.y)/(s.x-e.x);

            b=s.y-k*s.x;

        }

        bool operator==(const Line&r) const{

            int x1,x2,y1,y2;

            x1=e.x-s.x;

            y1=e.y-s.y;

            x2=r.e.x-r.s.x;

            y2=r.e.y-r.s.y;

            return x1*y2-y1*x2==0;

        }

    };

    struct Hash{

        size_t operator()(const Line&a) const{

            auto h=hash<int>();

            auto z= a.k%2;
		if(!s.count(z)){
		s.insert(z);
		cout<<s.size()<<" - "<<endl;
		}
		return z;

        }  

    };

    int maxPoints(vector<Point> &points) {

        unordered_map<Line, int, Hash> dict;

        int mx=0;

        for(int i=0;i<points.size();i++)

            for(int j=1;j<points.size();j++){

                Line l(points[i],points[j]);

                if(dict.count(l))

                    dict[l]++;

                else

                    dict[l]=0;

                mx=max(mx,dict[l]);

            }

        return mx;

    }











int main(){

	vector<Point> p;
	for(int i=0;i<100;i++)
		for(int j=i+1;j<20;j++)
			p.push_back({i,j});
	cout<<maxPoints(p)<<endl<<s.size()<<endl;
}
