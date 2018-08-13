// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	cnt = 0;
	if (curr_node != nullptr) delete curr_node;
	curr_node = new Node('|');
	if (curr_node == nullptr) return;
	return;
}

void TypingMachine::HomeKey() {
	if (curr_node->GetPreviousNode() == nullptr) return;
	curr_node = curr_node->GetPreviousNode();
	curr_node->EraseNextNode();
	while (curr_node->GetPreviousNode() != nullptr) curr_node = curr_node->GetPreviousNode();
	curr_node->InsertPreviousNode('|');
	curr_node = curr_node->GetPreviousNode();
	return;
}

void TypingMachine::EndKey() {
	if (curr_node->GetNextNode() == nullptr) return;
	curr_node = curr_node->GetNextNode();
	curr_node->ErasePreviousNode();
	while (curr_node->GetNextNode() != nullptr) curr_node = curr_node->GetNextNode();
	curr_node->InsertNextNode('|');
	curr_node = curr_node->GetNextNode();
	return;
}

void TypingMachine::LeftKey() {
	if (curr_node->GetPreviousNode() == nullptr) return;
	curr_node = curr_node->GetPreviousNode();
	curr_node->EraseNextNode();
	curr_node->InsertPreviousNode('|');
	curr_node = curr_node->GetPreviousNode();
	return;
}

void TypingMachine::RightKey() {
	if (curr_node->GetNextNode() == nullptr) return;
	curr_node = curr_node->GetNextNode();
	curr_node->ErasePreviousNode();
	curr_node->InsertNextNode('|');
	curr_node = curr_node->GetNextNode();
	return;
}

bool TypingMachine::TypeKey(char key) {
	if (cnt == 100) return false;
	curr_node->InsertPreviousNode(key);
	cnt++;
	return true;
}

bool TypingMachine::EraseKey() {
	if (cnt <= 0 || curr_node->GetPreviousNode() == nullptr) return false;
	curr_node->ErasePreviousNode();
	cnt--;
	return true;
}

std::string TypingMachine::Print(char separator) {
	std::string out_str = "";
	Node* prt_node = curr_node;
	while (prt_node->GetPreviousNode() != nullptr) { prt_node = prt_node->GetPreviousNode(); }
	while (prt_node != nullptr) {
		out_str += prt_node->GetData();
		prt_node = prt_node->GetNextNode();
	}
    return out_str;
}
