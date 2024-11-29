class Solution {
public:
    std::string simplifyPath(const std::string& path) {
        std::stack<std::string> st;
        std::stringstream ss(path);
        std::string component;

        while (std::getline(ss, component, '/')) {
            if(component == "" or component == "."){
                continue;
            }
            else if (component == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else{
                st.push(component);
            }
        }

        std::vector<std::string> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        std::reverse(result.begin(), result.end());

        std::string canonicalPath = "/";
        for (size_t i = 0; i < result.size(); ++i) {
            canonicalPath += result[i];
            if (i != result.size() - 1) {
                canonicalPath += "/";
            }
        }

        return canonicalPath;
    }

};
