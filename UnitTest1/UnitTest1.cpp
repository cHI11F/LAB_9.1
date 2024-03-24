#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_9.1/LAB_9.1.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountStudentsWithoutThrees)
        {
            vector<Student> students = {
                {"Smith", 2, "Computer Science", 5, 4, 4},
                {"Johnson", 1, "Mathematics", 4, 3, 4},
                {"Williams", 3, "Physics", 3, 3, 3},
                {"Brown", 2, "Computer Science", 5, 5, 5},
                {"Jones", 1, "Mathematics", 4, 4, 4}
            };
            Assert::AreEqual(countStudentsWithoutThrees(students), 3);
        }

        TEST_METHOD(TestCalculatePercentageOfStudentsWithAverageBelowFour)
        {
            vector<Student> students = {
                {"Smith", 2, "Computer Science", 5, 4, 4},
                {"Johnson", 1, "Mathematics", 4, 3, 4},
                {"Williams", 3, "Physics", 3, 3, 3},
                {"Brown", 2, "Computer Science", 5, 5, 5},
                {"Jones", 1, "Mathematics", 4, 4, 4}
            };
            Assert::AreEqual(calculatePercentageOfStudentsWithAverageBelowFour(students), 40.0);
        }
    };
}
