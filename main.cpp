#include <iostream>
#include <map>
#include "Model/RubiksCube3dArray.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
using namespace std;
int main() {
    //std::cout << "Hello, World!" << std::endl;
    RubiksCube3dArray o;
    o.print();
    vector<RubiksCube::MOVE> movestossuffle = o.randomShuffleCube(3);
    o.print();
    for(auto move:movestossuffle) {
        cout<<o.getMove(move)<<" ";
    }
    cout<<endl;
    IDDFSSolver<RubiksCube3dArray,Hash3d> bfs_solver(o);
    vector<RubiksCube::MOVE> ans = bfs_solver.solve();
    for(auto move:ans) {
        cout<<o.getMove(move)<<" ";
    }
    cout<<endl;
    bfs_solver.rubiksCube.print();
}
