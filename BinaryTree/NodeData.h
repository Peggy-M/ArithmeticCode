#pragma once
class NodeData
{
public:
	NodeData* left;
	NodeData* right;
	int val;
	NodeData(int x) :val(x), left(nullptr), right(nullptr) {};
};

