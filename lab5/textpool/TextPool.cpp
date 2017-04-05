//
// Created by kornel on 02.04.17.
//

#include "TextPool.h"


TextPool::TextPool(const std::initializer_list<experimental::string_view> &elements) : s{elements}
{}
TextPool::TextPool() : s()
{}

//TextPool::TextPool(TextPool const &other) {
//    this->s=other.s;
//}

TextPool::TextPool(TextPool &&that){
    *this=move(that);
}

TextPool & TextPool::operator=(TextPool && that) noexcept
{
    if(this==&that)
        return that;
    this->s=that.s;
    that.s.clear();
    return *this;
}
TextPool::~TextPool() {
    s.clear();
}


size_t TextPool::StoredStringCount() const
{
    return s.size();
}
std::experimental::string_view TextPool::Intern(const std::string &str)
{
    if (s.find(str) != s.end()) {
        return *s.find(str);
    } else{
        experimental::string_view tmp=str;
        s.insert(tmp);
        return *s.find(str);
    }
}
