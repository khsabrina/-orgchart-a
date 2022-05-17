#include "doctest.h"
#include <iostream>
#include <string>
#include <vector>
#include "OrgChart.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("good inputs"){
    SUBCASE("Adding a root and subs"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));

    OrgChart<int> organization_int;
    CHECK_NOTHROW(organization_int.add_root(1));
    CHECK_NOTHROW(organization_int.add_sub(1, 2));
    CHECK_NOTHROW(organization_int.add_sub(1, 3));
    CHECK_NOTHROW(organization_int.add_sub(3, 4));
    CHECK_NOTHROW(organization_int.add_sub(2, 5));
    CHECK_NOTHROW(organization_int.add_sub(3, 6));
    }
    SUBCASE("level order iterator"){
        OrgChart organization;
        CHECK_NOTHROW(organization.add_root("CEO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
        CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
        OrgChart<int> organization_int;
        //checking the template
        CHECK_NOTHROW(organization_int.add_root(1));
        CHECK_NOTHROW(organization_int.add_sub(1, 2));
        CHECK_NOTHROW(organization_int.add_sub(1, 3));
        CHECK_NOTHROW(organization_int.add_sub(3, 4));
        CHECK_NOTHROW(organization_int.add_sub(2, 5));
        CHECK_NOTHROW(organization_int.add_sub(3, 6));
        vector<string> level_order{"CEO" ,"CTO" ,"CFO","COO" ,"VP_SW","VP_BI"};
        size_t count =0;
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
        {
            CHECK_EQ(level_order[count],(*it));
            count++;
        }
        vector<int> level_order_int{1 ,2 ,3 ,5 ,4 ,6};
        count =0;
        for (auto it = organization_int.begin_level_order(); it != organization_int.end_level_order(); ++it)
        {
            CHECK_EQ(level_order_int[count],(*it));
            count++;
        }  
    }
    SUBCASE("reverse level order iterator"){
        OrgChart organization;
        CHECK_NOTHROW(organization.add_root("CEO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
        CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
        //checking the template
        OrgChart<int> organization_int;
        CHECK_NOTHROW(organization_int.add_root(1));
        CHECK_NOTHROW(organization_int.add_sub(1, 2));
        CHECK_NOTHROW(organization_int.add_sub(1, 3));
        CHECK_NOTHROW(organization_int.add_sub(3, 4));
        CHECK_NOTHROW(organization_int.add_sub(2, 5));
        CHECK_NOTHROW(organization_int.add_sub(3, 6));
        vector<string> reverse_level_order{"VP_SW", "VP_BI", "CTO", "CFO", "COO", "CEO"};
        size_t count =0;
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
        {
            CHECK_EQ(reverse_level_order[count],(*it));
            count++;
        }
        vector<int> reverse_level_order_int{5, 4, 6 ,2 ,3 ,1};
        count =0;
        for (auto it = organization_int.begin_reverse_order(); it != organization_int.reverse_order(); ++it)
        {
            CHECK_EQ(reverse_level_order_int[count],(*it));
            count++;
        }  
    }
    SUBCASE("preorder iterator"){
        OrgChart organization;
        CHECK_NOTHROW(organization.add_root("CEO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
        CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
        //checking the template
        OrgChart<int> organization_int;
        CHECK_NOTHROW(organization_int.add_root(1));
        CHECK_NOTHROW(organization_int.add_sub(1, 2));
        CHECK_NOTHROW(organization_int.add_sub(1, 3));
        CHECK_NOTHROW(organization_int.add_sub(3, 4));
        CHECK_NOTHROW(organization_int.add_sub(2, 5));
        CHECK_NOTHROW(organization_int.add_sub(3, 6));
        vector<string> preorder{"CEO", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
        size_t count =0;
        for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
        {
            CHECK_EQ(preorder[count],(*it));
            count++;
        }
        vector<int> preorder_int{1,2 ,5, 3 ,4 ,6};
        count =0;
        for (auto it = organization_int.begin_preorder(); it != organization_int.end_preorder(); ++it)
        {
            CHECK_EQ(preorder_int[count],(*it));
            count++;
        }  
    }
    SUBCASE("iterator"){
        OrgChart organization;
        CHECK_NOTHROW(organization.add_root("CEO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
        CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
        //checking the template
        OrgChart<int> organization_int;
        CHECK_NOTHROW(organization_int.add_root(1));
        CHECK_NOTHROW(organization_int.add_sub(1, 2));
        CHECK_NOTHROW(organization_int.add_sub(1, 3));
        CHECK_NOTHROW(organization_int.add_sub(3, 4));
        CHECK_NOTHROW(organization_int.add_sub(2, 5));
        CHECK_NOTHROW(organization_int.add_sub(3, 6));
        vector<string> level_order{"CEO" ,"CTO" ,"CFO","COO" ,"VP_SW","VP_BI"};
        int count =0;
        for (auto element : organization)
        { 
            CHECK_EQ(element,level_order[(size_t)count]);
            count++;
        } 
        vector<int> level_order_int{1 ,2 ,3 ,5 ,4 ,6};
        count =0;
        for (auto element : organization_int)
        { 
            CHECK_EQ(level_order_int[(size_t)count],element);
            count++;
        }
    }
}
TEST_CASE("bad inputs"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
    CHECK_THROWS(organization.add_sub("Not inside of the OrgChart", "VP_BI"));
    CHECK_THROWS(organization.add_sub("Not inside of the OrgChart2", "COO"));
    CHECK_THROWS(organization.add_sub("Not inside of the OrgChart3", "Sabrina"));
    OrgChart<int> organization_int;
    CHECK_NOTHROW(organization_int.add_root(1));
    CHECK_NOTHROW(organization_int.add_sub(1, 2));
    CHECK_NOTHROW(organization_int.add_sub(1, 3));
    CHECK_NOTHROW(organization_int.add_sub(3, 4));
    CHECK_NOTHROW(organization_int.add_sub(2, 5));
    CHECK_NOTHROW(organization_int.add_sub(3, 6));
    CHECK_THROWS(organization_int.add_sub(7,6));
    CHECK_THROWS(organization_int.add_sub(8,8));
    CHECK_THROWS(organization_int.add_sub(9,2));
}
