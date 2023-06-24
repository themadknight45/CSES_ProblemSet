for(int i=0;i<n-1;i++){
        int x,y;
        std::cin >> x;
        std::cin >> y;
        x--;y--;
        graph[x].push_back(y);graph[y].push_back(x);
    }