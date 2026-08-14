#pragma once

#include <vector>
#include <string>

class Inventory {
    private:
        std::vector<std::string> items_;

    public:
        void add(const std::string& item);
        bool remove(const std::string& item); // absent item: no-op, cycle 4 proves it
        bool has(const std::string& item) const;
        int count() const;
};
