#include <iostream>
#include <vector>

int main()
{
    int num_tests = 0;
    std::cin >> num_tests; 

    for (int t = 0; t < num_tests; ++t)
    {
        int n, m;
        std::cin >> n >> m;

        int b_turns = 0;
        int prev = -1; 
        int height; 
        
        for (int i = 0; i < n; ++i) 
        {
            std::cin >> height;
            if (prev != -1)
            {
                b_turns += prev - height + 1;
            }
            prev = height; 
        }
        b_turns += height; 
        
        int v_turns = 0;
        prev = -1;
        for (int i = 0; i < m; ++i) 
        {
            std::cin >> height;
            if (prev != -1)
            {
                v_turns += prev - height + 1;
            }
            prev = height; 
        }
        v_turns += height;

        if (b_turns >= v_turns)
        {
            std::cout << "1\n";
        }
        else
        {
            std::cout << "2\n";
        }
    }
}
