// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

public:
  static void RunTest() {
    BarSeparatorTest();
  }
};

class TmTypeKeyTestSuite
{
private:
	static void TypeKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		ASSERT_EQ(tm.Print('|'), "a|");
		tm.TypeKey(30);
		ASSERT_EQ(tm.Print('|'), "a|");
		tm.TypeKey(130);
		ASSERT_EQ(tm.Print('|'), "a|");
		tm.TypeKey('b');
		ASSERT_EQ(tm.Print('|'), "ab|");
		tm.TypeKey('c');
		ASSERT_EQ(tm.Print('|'), "abc|");
	}

public:
	static void RunTest() {
		TypeKeyTest();
	}
};

class TmEraseKeyTestSuite
{
private:
	static void EraseKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), "ab|");
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), "a|");
		bool val = tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), "|");
		ASSERT_EQ(val, true);
		val = tm.EraseKey();
		ASSERT_EQ(val, false);
	}

public:
	static void RunTest() {
		EraseKeyTest();
	}
};

class TmMoveKeyTestSuite
{
private:
	static void LeftKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), "ab|c");
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), "a|bc");
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), "|abc");
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), "|abc");
	}

	static void RightKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), "|abc");
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), "a|bc");
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), "ab|c");
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), "abc|");
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), "abc|");
	}

public:
	static void RunTest() {
		LeftKeyTest();
		RightKeyTest();
	}
};

class TmHomeEndTestSuite
{
private:
	static void HomeKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), "|abc");
	}

	static void EndKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), "|abc");
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), "abc|");
	}

public:
	static void RunTest() {
		HomeKeyTest();
		EndKeyTest();
	}
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  TmTypeKeyTestSuite::RunTest();
  TmEraseKeyTestSuite::RunTest();
  TmMoveKeyTestSuite::RunTest();
  TmHomeEndTestSuite::RunTest();
}