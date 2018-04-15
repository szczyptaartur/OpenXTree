#pragma once
class TreeNode { //klasa z wlasciwosciami wezlow
public:

	int value;
	int number;
	TreeNode  *right;
	TreeNode *left;
	TreeNode();
	TreeNode(int valuee, int numberr);
	~TreeNode() = default;
};