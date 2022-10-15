#pragma once

#include <boost/serialization/string.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <string>
#include <fstream>

namespace fox {

    class Test {
    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            ar & a & s;
        }
        
    public:
        int a;
        std::string s;
    };

    inline void test_save() {
        std::ofstream ofs("test.txt");
        boost::archive::text_oarchive oa(ofs);
        Test test;
        test.a = 42;
        test.s = "Timur";
        oa << test;
    }
}
