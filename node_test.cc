// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }

  static void MultiNodeTest() {
	  Node *node1 = new Node('A');
	  ASSERT_EQ(node1->GetData(), 'A');
	  Node *node2 = new Node('B');
	  ASSERT_EQ(node2->GetData(), 'B');
	  delete node1;
	  delete node2;
  }

public:
  static void RunTest() {
    SingleNodeTest();
	MultiNodeTest();
  }
};

class NodeGetDataTestSuite
{
private:
	static void SingleNodeTest() {
		Node *node = new Node('X');
		ASSERT_EQ(node->GetData(), 'X');
		delete node;
	}

public:
	static void RunTest() {
		SingleNodeTest();
		// add more..
	}
};

class NodeGetNodeTestSuite
{
private:
	static void GetNextNodeTest() {
		Node *node = new Node('A');
		node->InsertNextNode('B');
		Node *next_node = node->GetNextNode();
		ASSERT_EQ(next_node->GetData(), 'B');
		node->InsertNextNode('C');
		next_node = node->GetNextNode();
		ASSERT_EQ(next_node->GetData(), 'C');
		delete node;
	}

	static void GetPreviousNodeTest() {
		Node *node = new Node('A');
		node->InsertPreviousNode('B');
		Node *prev_node = node->GetPreviousNode();
		ASSERT_EQ(prev_node->GetData(), 'B');
		node->InsertPreviousNode('C');
		prev_node = node->GetPreviousNode();
		ASSERT_EQ(prev_node->GetData(), 'C');
		delete node;
	}

public:
	static void RunTest() {
		GetNextNodeTest();
		GetPreviousNodeTest();
	}
};

class NodeInsertNodeTestSuite
{
private:
	static void InsertNextNodeTest() {
		Node *node = new Node('A');
		node->InsertNextNode('B');
		Node *next_node = node->GetNextNode();
		ASSERT_EQ(next_node->GetData(), 'B');
		delete node;
		delete next_node;
	}

	static void InserPreviousNodeTest() {
		Node *node = new Node('B');
		node->InsertPreviousNode('A');
		Node *prev_node = node->GetPreviousNode();
		ASSERT_EQ(prev_node->GetData(), 'A');
		delete node;
		delete prev_node;
	}

public:
	static void RunTest() {
		InsertNextNodeTest();
		InserPreviousNodeTest();
	}
};

class NodeEraseNodeTestSuite
{
private:
	static void EraseNextNodeTest() {
		Node *node = new Node('A');
		node->InsertNextNode('D');
		node->InsertNextNode('C');
		node->InsertNextNode('B');
		node->EraseNextNode();
		ASSERT_EQ(node->GetNextNode()->GetData(), 'C');
		node->EraseNextNode();
		ASSERT_EQ(node->GetNextNode()->GetData(), 'D');
		bool val = node->EraseNextNode();
		ASSERT_EQ(val, true);
		val = node->EraseNextNode();
		ASSERT_EQ(val, false);
		delete node;
	}
	static void ErasePreviousNodeTest() {
		Node *node = new Node('A');
		node->InsertPreviousNode('D');
		node->InsertPreviousNode('C');
		node->InsertPreviousNode('B');
		node->ErasePreviousNode();
		ASSERT_EQ(node->GetPreviousNode()->GetData(), 'C');
		node->ErasePreviousNode();
		ASSERT_EQ(node->GetPreviousNode()->GetData(), 'D');
		bool val = node->ErasePreviousNode();
		ASSERT_EQ(val, true);
		val = node->ErasePreviousNode();
		ASSERT_EQ(val, false);
		delete node;
	}
public:
	static void RunTest() {
		EraseNextNodeTest();
		ErasePreviousNodeTest();
	}
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  NodeGetDataTestSuite::RunTest();
  NodeGetNodeTestSuite::RunTest();
  NodeInsertNodeTestSuite::RunTest();
  NodeEraseNodeTestSuite::RunTest();
}