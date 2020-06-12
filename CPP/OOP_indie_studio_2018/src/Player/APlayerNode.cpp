/*
** EPITECH PROJECT, 2019
** APlayerNode
** File description:
** Aplayer Ndoe
*/

#include "../../include/Player/APlayerNode.hpp"

APlayerNode::APlayerNode()
{
}

APlayerNode::~APlayerNode()
{
}

void APlayerNode::createMoves()
{
    _moves = new Moves(_node, _receiver, _manager, _type);
}