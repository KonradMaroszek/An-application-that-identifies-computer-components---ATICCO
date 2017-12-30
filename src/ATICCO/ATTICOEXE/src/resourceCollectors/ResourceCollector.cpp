#include "resourceCollectors/ResourceCollector.h"

int ResourceCollector::idCounter = 0;

ResourceCollector::ResourceCollector() :id(++idCounter)
{

}

ResourceCollector::~ResourceCollector()
{

}

int ResourceCollector::getId() const
{
    return id;
}
