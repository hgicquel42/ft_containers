#include "vector.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "pair.hpp"
#include <iostream>



// #include <map>
// using namespace std;
#include "map.hpp"
using namespace ft;

int	main(void)
{

    // std::cout << "Constructor Accessor :: \n";

    // map<int,int>    map;

    // for(int i = 5; i < 85; i++)
    //     map.insert(ft::make_pair(i,i));

    // std::cout << map.at(5) << "\n";
    // std::cout << map.at(55) << "\n";
    // std::cout << map.at(84) << "\n";

    // std::cout << map[5] << "\n";
    // std::cout << map[55] << "\n";
    // std::cout << map[84] << "\n";
    // std::cout << map[85] << "\n";

    // map[85] = 85;

    // std::cout << map[85] << "\n";

    // std::cout << "-------------------\n";

    // ft::map<int,int>    map2(map.begin(), map.end());

    // std::cout << map2.at(5) << "\n";
    // std::cout << map2.at(55) << "\n";
    // std::cout << map2.at(84) << "\n";

    // std::cout << map2[5] << "\n";
    // std::cout << map2[55] << "\n";
    // std::cout << map2[84] << "\n";
    // std::cout << map2[85] << "\n";

    // std::cout << "-------------------\n";

    // ft::map<int,int>    map3(map);

    // std::cout << map3.at(5) << "\n";
    // std::cout << map3.at(55) << "\n";
    // std::cout << map3.at(84) << "\n";

    // std::cout << map3[5] << "\n";
    // std::cout << map3[55] << "\n";
    // std::cout << map3[84] << "\n";
    // std::cout << map3[85] << "\n";

    // std::cout << "Iterator ::\n";

    // map<int,int>    map;

    // for(int i = 5; i < 15; i++)
    //     map.insert(ft::make_pair(i,i));

    // ft::map<int,int>::iterator  it;
    // ft::map<int,int>::const_iterator  cit;
    // ft::map<int,int>::reverse_iterator  rit;
    // ft::map<int,int>::const_reverse_iterator  crit;

    // for(it = map.begin(); it != map.end(); it++)
    //     std::cout << (*it).first << " " << (*it).second << "\n";

    // std::cout << "-------------------\n";

    // it = map.end();
    // it--;
    // for(; it != map.begin(); it--)
    //     std::cout << (*it).first << " " << (*it).second << "\n";

    // std::cout << "-------------------\n";

    // for(cit = map.begin(); cit != map.end(); cit++)
    //     std::cout << (*cit).first << " " << (*cit).second << "\n";

    // std::cout << "-------------------\n";

    // cit = map.end();
    // cit--;
    // for(; cit != map.begin(); cit--)
    //     std::cout << (*cit).first << " " << (*cit).second << "\n";


    // std::cout << "Capacity ::\n";

    // map<int,int>    map;

    // if (map.empty())
    //     std::cout << "OKK\n";
    // std::cout << map.size() << "\n";
    // for(int i = 5; i < 15; i++)
    //     map.insert(ft::make_pair(i,i));
    // if (map.empty())
    //     std::cout << "KKO\n";

    // std::cout << map.size() << "\n";

    // map.erase(7);

    // std::cout << map.size() << "\n";

    // std::cout << map.max_size() << "\n";

    // std::cout << "Modifier\n";

    //  map<int,int>    map;

    // for(int i = 5; i < 85; i++)
    //     map.insert(ft::make_pair(i,i));

    // map.clear();

    // if (map.empty())
    //     std::cout << "OK\n";
    
    // for(int i = 5; i < 85; i++)
    //     map.insert(ft::make_pair(i,i));

    // ft::map<int,int>    map2;

    // map2.insert(map.begin(), map.end());

    // ft::map<int,int>::iterator  it;

    // for(it = map2.begin(); it != map2.end(); it++)
    //     std::cout << (*it).first << " " << (*it).second << "\n";

    // map.erase(map.begin(), map.end());

    // if(map.empty())
    //     std::cout << "OK\n";
    std::cout << "LookUp ::\n";

     ft::map<int,int>    map;

    for(int i = 5; i < 85; i += 5)
        map.insert(ft::make_pair(i,i));

    std::cout << map.count(12) << "\n";
    std::cout << map.count(120) << "\n";

    std::cout << (*(map.find(20))).first << " " << (*(map.find(20))).second << "\n";

    // std::cout << (*(map.find(200))).first << " " << (*(map.find(200))).second << "\n"; // SEGFAULT NORMAL

    std::cout << (*(map.lower_bound(18))).first << " " << (*(map.lower_bound(18))).second << "\n";

    std::cout << (*(map.upper_bound(18))).first << " " << (*(map.upper_bound(18))).second << "\n";

    map.equal_range(62);


    return (0);
}