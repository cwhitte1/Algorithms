
#include <tuple>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>

void graph_info(const std::vector<std::vector<int>> &difficulties){
	size_t count = 0;
	bool directed = true;
	bool negatives = false;

	for(size_t i = 0; i < difficulties.size(); ++i){
		for(size_t j = 0; j < difficulties.size(); ++j){
			if(difficulties[i][j] < 1000000000){
				++count;
			}
			if(directed && difficulties[i][j] != difficulties[j][i]){
				directed = false;
			}

			if((!negatives) && difficulties[i][j] < 0){
				negatives = true;
			}
		}
	}
	std::cout<<"\n";
	std::cout<<"Graph Density Info:\n";
	std::cout<<difficulties.size()<<" vertices\n";
	std::cout<<count<<" edges\n";
	if(!directed) {
		std::cout<<"un";
	}
	std::cout<<"directed\n";
	if(!negatives){
		std::cout<<"no negative weights\n";
	}
	std::cout<<"\n";
}

void print_matrix(const std::vector<std::vector<int>> &difficulties){
	if(difficulties.size() > 100){
		return;
	} else {
		std::cout<<std::endl;
		for(auto i:difficulties){
			std::cout<<"{";
			for(auto j:i){
				std::cout<<j<<",";
			}
			std::cout<<"}";
			std::cout<<std::endl;
		}
	}
}

namespace {
	size_t call_count = 0;
}
std::tuple<std::vector<std::vector<int>>,std::vector<std::vector<int>>> crossCountryChallenge(const std::vector<std::vector<int>> &difficulties) {

	std::vector<std::vector<int>> dist {difficulties};
	std::vector<std::vector<int>> pred {difficulties};

	for(size_t i = 0; i < difficulties.size(); ++i){
		pred[i].assign(pred.size(), i);
		pred[i][i] = -1;
	}

	for(size_t k = 0; k < difficulties.size(); ++k){
		for(size_t i = 0; i < difficulties.size(); ++i){
			for(size_t j = 0; j < difficulties.size(); ++j){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					pred[i][j] = pred[k][j];
				}
			}
		}
	}
	return std::make_tuple(dist, pred);
}


















