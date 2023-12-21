// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "C:\Users\andre\source\repos\LAB2OPPO\LAB2OPPO\zan.h"
#include "C:\Users\andre\source\repos\LAB2OPPO\LAB2OPPO\main.cpp"
#include "C:\Users\andre\source\repos\LAB2OPPO\LAB2OPPO\date1.h"
#include "C:\Users\andre\source\repos\LAB2OPPO\LAB2OPPO\zan.cpp"
#include "C:\Users\andre\source\repos\LAB2OPPO\LAB2OPPO\date1.cpp"
#include "C:\Users\andre\source\repos\LAB2OPPO\LAB2OPPO\time1.h"
#include "C:\Users\andre\source\repos\LAB2OPPO\LAB2OPPO\time1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(LoadTest)
	{
	public:
		TEST_METHOD(ValidData)
		{
			std::vector<Zan> data;
			std::istringstream input("2020.10.15 12:34 John");
			int size = load(data, input);

			Assert::AreEqual(size, 1);
			Assert::AreEqual(data[0].currdate.year, 2020);
			Assert::AreEqual(data[0].currdate.month, 10);
			Assert::AreEqual(data[0].currtime.hour, 12);
			string namech = "John";
			Assert::AreEqual(data[0].name, namech);
		}

		TEST_METHOD(InvalidData)
		{
			std::vector<Zan> data;
			std::istringstream input("2020/10/15 12$34 John");

			Assert::ExpectException<std::runtime_error>([&] {
				load(data, input);
				});
		}
	};

	TEST_CLASS(DateTest)
	{
	public:
		TEST_METHOD(ValidDate)
		{
			date1 d;
			std::istringstream input("2020.10.15");
			d.set_Date(input);

			Assert::AreEqual(d.year, 2020);
			Assert::AreEqual(d.month, 10);
			Assert::AreEqual(d.day, 15);
		}

		TEST_METHOD(InvalidDate)
		{
			date1 d;
			std::istringstream input("2020.15.40");

			Assert::ExpectException<std::runtime_error>([&] {
				d.set_Date(input);
				});
		}
	};

	TEST_CLASS(TimeTest)
	{
	public:
		TEST_METHOD(ValidTime)
		{
			Time1 t;
			std::istringstream input("12:34");
			t.set_time(input);

			Assert::AreEqual(t.hour, 12);
			Assert::AreEqual(t.min, 34);
		}

		TEST_METHOD(InvalidTime)
		{
			Time1 t;
			std::istringstream input("ab:jfj");

			Assert::ExpectException<std::runtime_error>([&] {
				t.set_time(input);
				});
		}
	};
}
