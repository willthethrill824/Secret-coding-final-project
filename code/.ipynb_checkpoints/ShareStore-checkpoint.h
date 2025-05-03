#ifndef SHARESTORE_H
#define SHARESTORE_H

#include <vector>
#include "Share.h"

class ShareStore {
private:
    std::vector<Share> shares;

public:
    void addShare(const Share& s);
    std::vector<Share> getKRandomShares(int k) const;
    void printShares() const;
    int size() const;
};

#endif
