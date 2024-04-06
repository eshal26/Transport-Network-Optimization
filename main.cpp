#include <iostream>
#include <cstdlib>
#include <chrono>
#include "Graph.h"
using namespace std;
//using chrono library to measure time
using namespace std::chrono;

//initialize startNode and endNode
string startNode, endNode;

//MainMenu function
void menu();

//shortest distance by dijkstra
void shortest_distance_dij(Graph graph, string ss);
//shortest distance by A*
void shortest_distance_Astar(Graph& graph, const string& ss);

//main function
int main()
{

    //Main menu
    menu();

    return 0;
}

//menu function containing main menu of program
void menu()
{
    //chrono libraries for time
    using chrono::duration;
    using chrono::duration_cast;
    using chrono::high_resolution_clock;
    using chrono::milliseconds;

    //while loop of main
    while(1)
    {
        int n;
        //initializing graph
        Graph graph;

        //clear screen
        system("cls");
        cout << "\n\n\t\t=================================================";
        cout << "\n\t\t||  Welcome to Transport Network optimization  ||";
        cout << "\n\t\t=================================================\n\n";

        //get input of startNode
        cout << "\n\t Enter Starting City : ";
        cin >> startNode;

        //get input of endNode
        cout << "\n\t Enter Destination City : ";
        cin >> endNode;

        //menu options
        cout << "\n\n\t1. Optimization on basis of distance. \n";
        cout << "\t2. Optimization on basis of cost. \n";
        cout << "\t3. Optimization on basis of time. \n";
        cout << "\n\tChoose one : ";
        cin >> n;

        //switch case containing options
        switch(n)
        {
            //Optimization on distance basis
        case 1:
            graph.readFileAndCreateGraph("total_distance.csv", graph);
            cout << "\n\t------------------------------------\n";
            cout << "\t\tDIJKSTRA'S ALGORITHIM: \n";
            cout << "\t------------------------------------\n";
            shortest_distance_dij(graph,"distance");
            cout << "\t------------------------------------\n";
            cout << "\t\tA-STAR ALGORITHIM: \n";
            cout << "\t------------------------------------\n";

            shortest_distance_Astar(graph,"distance");

            break;


        //Optimization on cost basis
        case 2:
            graph.readFileAndCreateGraph("total_cost.csv", graph);
            cout << "\n\t------------------------------------\n";
            cout << "\t\tDIJKSTRA'S ALGORITHIM: \n";
            cout << "\t------------------------------------\n";
            shortest_distance_dij(graph,"cost");
            cout << "\t------------------------------------\n";
            cout << "\t\tA-STAR ALGORITHIM: \n";
            cout << "\t------------------------------------\n";

            shortest_distance_Astar(graph,"cost");

            break;

        //Optimization on Time basis

        case 3:
            graph.readFileAndCreateGraph("time_road.csv", graph);
            cout << "\n\t------------------------------------\n";
            cout << "\t\tDIJKSTRA'S ALGORITHIM: \n";
            cout << "\t------------------------------------\n";
            shortest_distance_dij(graph,"time");
            cout << "\t------------------------------------\n";
            cout << "\t\tA-STAR ALGORITHIM: \n";
            cout << "\t------------------------------------\n";

            shortest_distance_Astar(graph,"time");

            break;

            //wrong input case
        default:
            cout << "\nWrong Input\n.";
            break;



        }
        //pause screen
        system("pause");
    }
}

//show shortest distance by dijkstra
void shortest_distance_dij(Graph graph, string ss)
{
    int shortest;

    //Check time by using chrono func
    auto t1 = high_resolution_clock::now();
    shortest = graph.dijkstra(startNode, endNode);
    auto t2 = high_resolution_clock::now();

    //if no path found.
    if(shortest == -1 || shortest == 0)
    {
        cout << "\n\t No path found between " << startNode << " and " << endNode << ". \n ";
        cout << "\n\n";
    }
    else
    {
        //if path found
        cout << "\n\t\tPATH FOUND:" << endl;
        cout << "\n\t Least "<< ss <<"  between " << startNode << " and " << endNode << " is: "  << shortest << " units.\n" << endl;
        auto ms_int = duration_cast<milliseconds>(t2 - t1);
        duration<double, std::milli> ms_double = t2 - t1;

        //output the time calculated.
        cout << "\n\t\tTIME TAKEN:\n" << endl;
        cout << "\t Time taken by Dijkstra's function: \n" ;
        cout << "\t " << ms_int.count() << "ms\n";
        cout << "\t " << ms_double.count() << "ms" << endl;
        cout << "\n\n";

    }


}

//show shortest distance by A*
void shortest_distance_Astar(Graph& graph, const string& ss)
{

    int shortest;
    //calculate time using chrono func
    auto t1 = high_resolution_clock::now();
    shortest = graph.astar(startNode, endNode);
    auto t2 = high_resolution_clock::now();

    //if no node found
    if (shortest == -1)
    {
        cout << "\n\t No path found between " << startNode << " and " << endNode << ". \n ";
        cout << "\n\n";
    }

    else
    {   //if path found, print
        cout << "\n\t\tPATH FOUND:" << endl;
        cout << "\n\t Least " << ss << "  between " << startNode << " and " << endNode << " is: " << shortest << " units.\n" << endl;
        auto ms_int = duration_cast<milliseconds>(t2 - t1);
        duration<double, std::milli> ms_double = t2 - t1;

        //output the time calculated
        cout << "\n\t\tTIME TAKEN:\n" << endl;
        cout << "\t Time taken by A* function: \n" ;
        cout << "\t " << ms_int.count() << "ms\n";
        cout << "\t " << ms_double.count() << "ms" << endl;
        cout << "\n\n";
        cout << "\n\n";
    }
}



