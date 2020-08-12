#pragma once
#include <string>
#include <vector>

namespace libreadfile
{
    class ReadFile
    {
    public:
        ReadFile(std::string fileName);
        void read();
        int getLineCount();
        std::vector<std::string> getLines();
        virtual ~ReadFile();

    private:
        std::string fileName;
        std::vector<std::string> lines;
        int lineCount = 0;
    };
} // namespace libreader