#include "graphedge.h"
#include "graphnode.h"
#include<iostream>
using namespace std;

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    //// 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(shared_ptr<GraphEdge> edge)
{
    weak_ptr<GraphEdge> a=edge;
    _parentEdges.push_back(a);
}

void GraphNode::AddEdgeToChildNode(shared_ptr<GraphEdge> edge)
{
    _childEdges.push_back(edge);
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(unique_ptr<ChatBot> chatbot)
{
    std::cout<<"hello";
    _chatBot = std::move(chatbot);
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(shared_ptr<GraphNode> newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

shared_ptr<GraphEdge> GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index];

    ////
    //// EOF STUDENT CODE
}