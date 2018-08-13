// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	stored_char = '|';
	prev_node = nullptr;
	next_node = nullptr;
	curr_node = this;
	return;
}

void TypingMachine::HomeKey() {
	while (curr_node->prev_node != nullptr)
	{
		curr_node->stored_char = curr_node->prev_node->stored_char;
		curr_node = curr_node->prev_node;
		curr_node->stored_char = '|';
	}
	return;
}

void TypingMachine::EndKey() {
	while (curr_node->next_node != nullptr) {
		curr_node->stored_char = curr_node->next_node->stored_char;
		curr_node = curr_node->next_node;
		curr_node->stored_char = '|';
	}
	return;
}

void TypingMachine::LeftKey() {
	if (curr_node->prev_node == nullptr) return;
	char t_char = curr_node->prev_node->stored_char;
	curr_node->prev_node->stored_char = '|';
	curr_node->stored_char = t_char;
	curr_node = curr_node->prev_node;
	return;
}

void TypingMachine::RightKey() {
	if (curr_node->next_node == nullptr) return;
	curr_node->stored_char = curr_node->next_node->stored_char;
	curr_node->next_node->stored_char = '|';
	curr_node = curr_node->next_node;
	return;
}

bool TypingMachine::TypeKey(char key) {
	if (cnt == 100) return false;
	TypingMachine* new_node = new TypingMachine();
	new_node->stored_char = key;
	if (curr_node->prev_node == nullptr) {
		curr_node->prev_node = new_node;
		new_node->next_node = curr_node;
	}
	else {
		TypingMachine* t_prev_node = curr_node->prev_node;
		curr_node->prev_node = new_node;
		new_node->prev_node = t_prev_node;
		new_node->next_node = curr_node;
		t_prev_node->next_node = new_node;
	}
	cnt++;
	return true;
}

bool TypingMachine::EraseKey() {
	if (curr_node->prev_node == nullptr) return false;
 	if (cnt <= 0) return false;
 	cnt--;
 	TypingMachine* t_prev_node = curr_node->prev_node;
 	curr_node->prev_node = t_prev_node->prev_node;
 	if (t_prev_node->prev_node != nullptr) t_prev_node->prev_node->next_node = curr_node;
 	delete t_prev_node;
	return false;
}

std::string TypingMachine::Print(char separator) {
	std::string out_str = "";
	TypingMachine* node = this;
	while (node->prev_node != nullptr) node = node->prev_node;
	while (node != nullptr) {
		out_str += node->stored_char;
		node = node->next_node;
	}
  return out_str;
}
