// Copyright 2018 <Author>

#include "typing_machine.h"

#define START_IDX 1
#define END_IDX 130
#define MAX_KEY_COUNT 100

TypingMachine::TypingMachine() {
	if (start_node != nullptr) delete start_node;
	if (end_node != nullptr) delete end_node;
	start_node = end_node = nullptr;

	cnt = 0;

	start_node = new Node(START_IDX);
	if (start_node == 0) return;
	end_node = start_node->InsertNextNode(END_IDX);
	if (end_node == 0) return;	
	curr_node = end_node;
  return;
}

void TypingMachine::HomeKey() {
	if (start_node == nullptr) return;
	curr_node = start_node->GetNextNode();
	return;
}

void TypingMachine::EndKey() {
	curr_node = end_node;
	return;
}

void TypingMachine::LeftKey() {
	if (curr_node == nullptr) return;
	if (curr_node->GetPreviousNode() == start_node) return;
	curr_node = curr_node->GetPreviousNode();
	return;
}

void TypingMachine::RightKey() {
	if (curr_node == end_node) return;
	curr_node = curr_node->GetNextNode();
	return;
}

bool TypingMachine::TypeKey(char key) {
	if (MAX_KEY_COUNT <= cnt) return false;
	if (curr_node == nullptr) return false;
	if (key < 32 || 126 < key) return false;
	if (curr_node->InsertPreviousNode(key) == nullptr) {
		return false;
	}
	cnt++;
	return true;
}

bool TypingMachine::EraseKey() {
	if (cnt <= 0) return false;
	if (curr_node == nullptr) return false;
	if (curr_node->GetPreviousNode() == start_node) return false;
	if (curr_node->ErasePreviousNode() == false) return false;
	cnt--;
    return true;
}

std::string TypingMachine::Print(char separator) {
	std::string out_str = "";
	Node* prt_node = start_node->GetNextNode();
	while (prt_node != end_node) {
		if (prt_node == curr_node) {
			if (separator != 0) out_str += separator;
		}
		out_str += prt_node->GetData();
		prt_node = prt_node->GetNextNode(); 
	}
	if (prt_node == curr_node && separator != 0) out_str += separator;
	return out_str;
}
