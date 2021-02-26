#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<shared_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    std::vector<weak_ptr<GraphEdge>> _parentEdges; // edges to preceding nodes 
    unique_ptr<ChatBot> _chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    shared_ptr<GraphEdge> GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(shared_ptr<GraphEdge> edge);
    void AddEdgeToChildNode(shared_ptr<GraphEdge> edge);

    //// STUDENT CODE
    ////

    void MoveChatbotHere(unique_ptr<ChatBot> chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(shared_ptr<GraphNode> newNode);
};

#endif /* GRAPHNODE_H_ */