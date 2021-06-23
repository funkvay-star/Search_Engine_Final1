#include "LoadResult.h"



LoadResult::LoadResult()
    : status{}, body{}
{

}

LoadResult::LoadResult(long Status, std::shared_ptr<std::string> Body, std::string EffectiveUrl) 
    : status(Status), body(Body), effectiveUrl(EffectiveUrl)
{
    //std::cout << "effectiveUrl in LoadResult.cpp ->" << effectiveUrl << "\n";
    //std::cout << "EffectiveUrl in LoadResult.cpp ->" << EffectiveUrl << "\n\n";
}

LoadResult::LoadResult(int ErrorCode)
: errorCode(ErrorCode)
{

}


std::shared_ptr<std::string> LoadResult::getBody()
{
    return body;
}

std::string LoadResult::getEffectiveUrl()
{
    return effectiveUrl;
}

long LoadResult::getStatus()
{
    return status;
}

int LoadResult::getErrorCode()
{
    return errorCode;
}