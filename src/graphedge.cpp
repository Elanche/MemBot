#include "graphnode.h"
#include "graphedge.h"

GraphEdge::GraphEdge(int id)
{
    _id = id;
}

void GraphEdge::SetChildNode(shared_ptr<GraphNode> childNode)
{
    _childNode = childNode;
}

void GraphEdge::SetParentNode(shared_ptr<GraphNode> parentNode)
{
    _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token)
{
    _keywords.push_back(token);
}