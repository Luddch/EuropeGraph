#include <iostream>
#include <vector>
#include <set>
enum Europe{RUSSIA,UKRAINE,BELARUS,ESTONIA,LATVIA,LITHUANIA,FINLAND,NORWAY,SWEDEN,POLAND,MOLDOVA,SLOVAKIA,ROMANIA,CZECHIA,HUNGARY,SERBIA,BULGARIA,
    MACEDONIA,GREECE,TURKEY,GEORGIA,ALBANIA,MONTENEGRO,BOSNIA,CROATIA,SLOVENIA,AUSTRIA,GERMANY,DENMARK,NETHERLANDS,BELGIUM,LIECHTENSTEIN,
    LUXEMBOURG,SWITZERLAND,FRANCE,MONACO,ITALY,SANMARINO,VATICAN,ANDORRA,SPAIN,PORTUGAL};

std::vector<std::string> EuropeOutput{"RUSSIA","UKRAINE","BELARUS","ESTONIA","LATVIA","LITHUANIA","FINLAND","NORWAY","SWEDEN","POLAND","MOLDOVA","SLOVAKIA","ROMANIA","CZECHIA","HUNGARY","SERBIA","BULGARIA",
                            "MACEDONIA","GREECE","TURKEY","GEORGIA","ALBANIA","MONTENEGRO","BOSNIA","CROATIA","SLOVENIA","AUSTRIA","GERMANY","DENMARK","NETHERLANDS","BELGIUM","LIECHTENSTEIN",
                            "LUXEMBOURG","SWITZERLAND","FRANCE","MONACO","ITALY","SANMARINO","VATICAN","ANDORRA","SPAIN","PORTUGAL"};
struct Edge {
    Europe country;
    std::vector<std::pair<int,Europe>> edge;
    Edge(Europe Country,const std::vector<std::pair<int,Europe>>& _edge){
        country = Country;
        edge = _edge;
    }
    Edge() = default;
};



void PrimSpanningTree(std::vector<Edge>& adjacencyList){
    std::vector<std::pair<Edge,std::vector<std::pair<Europe,int>>>> SpanningTree;
    std::set<Europe> unvisited;

    for(int i =1;i<adjacencyList.size();i++){
        unvisited.emplace((Europe)i);
    }
    SpanningTree.emplace_back(std::make_pair(adjacencyList[0],0));

    while(!unvisited.empty()){
        int minDistance = INT32_MAX;
        std::pair<int,Europe> edge;
        for(int i =0;i<SpanningTree.size();i++){
            for(int j =0;j<SpanningTree[i].first.edge.size();j++){
                if(minDistance > SpanningTree[i].first.edge[j].first && unvisited.contains(SpanningTree[i].first.edge[j].second)){
                    minDistance = SpanningTree[i].first.edge[j].first;
                    edge.first = i;
                    edge.second = SpanningTree[i].first.edge[j].second;
                }
            }
        }
        SpanningTree[edge.first].second.emplace_back(edge.second,minDistance);
        SpanningTree.emplace_back(std::make_pair(adjacencyList[edge.second],0));
        unvisited.erase(edge.second);
    }

   int TotalDistance =0;
    for(int i = 0;i < SpanningTree.size();i++) {
        std::cout <<"country: " << EuropeOutput[SpanningTree[i].first.country]  << std::endl;
        for(int j =0;j<SpanningTree[i].second.size();j++){
           std::cout << "distance: " <<  SpanningTree[i].second[j].second <<"  To: " << EuropeOutput[SpanningTree[i].second[j].first] << std::endl;
            TotalDistance += SpanningTree[i].second[j].second;
        }
     std::cout << std::endl;
    }
  std::cout << "TotalDistance: " << TotalDistance << std::endl;

}

int main() {
    std::vector<Edge> AdjacencyList;
    AdjacencyList.resize(42);
    Edge russia(RUSSIA, {
            std::make_pair(761, UKRAINE),
            std::make_pair(673, BELARUS),
            std::make_pair(869, ESTONIA),
            std::make_pair(835, LATVIA),
            std::make_pair(788, LITHUANIA),
            std::make_pair(1646, NORWAY),
            std::make_pair(890, FINLAND),
            std::make_pair(1158, POLAND),
            std::make_pair(1654, GEORGIA)
    });
    AdjacencyList[0] = russia;

    Edge ukraine(UKRAINE,{
            std::make_pair(761, RUSSIA),
            std::make_pair(436, BELARUS),
            std::make_pair(685, POLAND),
            std::make_pair(411, MOLDOVA),
            std::make_pair(1007, SLOVAKIA),
            std::make_pair(742, ROMANIA),
            std::make_pair(900, HUNGARY)
    });
    AdjacencyList[1] = ukraine;

    Edge belarus(BELARUS,{
            std::make_pair(673, RUSSIA),
            std::make_pair(436, UKRAINE),
            std::make_pair(408, LATVIA),
            std::make_pair(171, LITHUANIA),
            std::make_pair(476, POLAND)
    });
    AdjacencyList[2] = belarus;

    Edge estonia(ESTONIA,{
            std::make_pair(869, RUSSIA),
            std::make_pair(275, LATVIA)
    });
    AdjacencyList[3] = estonia;

    Edge latvia(LATVIA,{
            std::make_pair(835, RUSSIA),
            std::make_pair(408, BELARUS),
            std::make_pair(275, ESTONIA),
            std::make_pair(270, LITHUANIA)
    });
    AdjacencyList[4] = latvia;

    Edge lithuania(LITHUANIA,{
            std::make_pair(788, RUSSIA),
            std::make_pair(171, BELARUS),
            std::make_pair(270, LATVIA),
            std::make_pair(393, POLAND)
    });
    AdjacencyList[5] = lithuania;

    Edge finland(FINLAND,{
            std::make_pair(890, RUSSIA),
            std::make_pair(789, NORWAY),
            std::make_pair(390, SWEDEN)
    });
    AdjacencyList[6] = finland;

    Edge norway(NORWAY,{
            std::make_pair(1646, RUSSIA),
            std::make_pair(789, FINLAND),
            std::make_pair(406, SWEDEN)
    });
    AdjacencyList[7] = norway;

    Edge sweden(SWEDEN,{
            std::make_pair(406, NORWAY),
            std::make_pair(390, FINLAND)
    });
    AdjacencyList[8] = sweden;

    Edge poland(POLAND,{
            std::make_pair(1158, RUSSIA),
            std::make_pair(685, UKRAINE),
            std::make_pair(476, BELARUS),
            std::make_pair(270, LITHUANIA),
            std::make_pair(535, SLOVAKIA),
            std::make_pair(520, CZECHIA),
            std::make_pair(528, GERMANY)
    });
    AdjacencyList[9] = poland;

    Edge moldova(MOLDOVA,{
            std::make_pair(411, UKRAINE),
            std::make_pair(364, ROMANIA)
    });
    AdjacencyList[10] = moldova;

    Edge slovakia(SLOVAKIA,{
            std::make_pair(1007, UKRAINE),
            std::make_pair(535, POLAND),
            std::make_pair(290, CZECHIA),
            std::make_pair(165, HUNGARY),
            std::make_pair(54, AUSTRIA)
    });
    AdjacencyList[11] = slovakia;

    Edge romania(ROMANIA,{
            std::make_pair(742, UKRAINE),
            std::make_pair(364, MOLDOVA),
            std::make_pair(450, SERBIA),
            std::make_pair(295, BULGARIA),
            std::make_pair(644, HUNGARY)
    });
    AdjacencyList[12] = romania;

    Edge czechia(CZECHIA,{
            std::make_pair(520, POLAND),
            std::make_pair(290, SLOVAKIA),
            std::make_pair(255, AUSTRIA),
            std::make_pair(280, GERMANY)
    });
    AdjacencyList[13] = czechia;

    Edge hungary(HUNGARY,{
            std::make_pair(900, UKRAINE),
            std::make_pair(165, SLOVAKIA),
            std::make_pair(644, ROMANIA),
            std::make_pair(315, SERBIA),
            std::make_pair(308, CROATIA),
            std::make_pair(388, SLOVENIA),
            std::make_pair(221, AUSTRIA)
    });
    AdjacencyList[14] = hungary;

    Edge serbia(SERBIA,{
            std::make_pair(450, ROMANIA),
            std::make_pair(315, HUNGARY),
            std::make_pair(337, BULGARIA),
            std::make_pair(325, MACEDONIA),
            std::make_pair(403, ALBANIA),
            std::make_pair(280, MONTENEGRO),
            std::make_pair(197, BOSNIA),
            std::make_pair(371, CROATIA)
    });
    AdjacencyList[15] = serbia;

    Edge bulgaria(BULGARIA,{
            std::make_pair(295, ROMANIA),
            std::make_pair(337, SERBIA),
            std::make_pair(179, MACEDONIA),
            std::make_pair(524, GREECE),
            std::make_pair(856, TURKEY)
    });
    AdjacencyList[16] = bulgaria;

    Edge macedonia(MACEDONIA,{
            std::make_pair(325, SERBIA),
            std::make_pair(179, BULGARIA),
            std::make_pair(488, GREECE),
            std::make_pair(155, ALBANIA)
    });
    AdjacencyList[17] = macedonia;

    Edge greece(GREECE,{
            std::make_pair(524, BULGARIA),
            std::make_pair(488, MACEDONIA),
            std::make_pair(814, TURKEY),
            std::make_pair(511, ALBANIA)
    });
    AdjacencyList[18] = greece;

    Edge turkey(TURKEY,{
            std::make_pair(856, BULGARIA),
            std::make_pair(814, GREECE),
            std::make_pair(1027, GEORGIA)
    });
    AdjacencyList[19] = turkey;

    Edge georgia(GEORGIA,{
            std::make_pair(1654, RUSSIA),
            std::make_pair(1027, TURKEY)
    });
    AdjacencyList[20] = georgia;

    Edge albania(ALBANIA,{
            std::make_pair(403, SERBIA),
            std::make_pair(155, MACEDONIA),
            std::make_pair(511, GREECE),
            std::make_pair(130, MONTENEGRO)
    });
    AdjacencyList[21] = albania;

    Edge montenegro(MONTENEGRO,{
            std::make_pair(280, SERBIA),
            std::make_pair(130, ALBANIA),
            std::make_pair(170, BOSNIA),
            std::make_pair(456, CROATIA),
    });
    AdjacencyList[22] = montenegro;

    Edge bosnia(BOSNIA,{
            std::make_pair(197, SERBIA),
            std::make_pair(170, MONTENEGRO),
            std::make_pair(293, CROATIA)
    });
    AdjacencyList[23] = bosnia;

    Edge croatia(CROATIA,{
            std::make_pair(308, HUNGARY),
            std::make_pair(371, SERBIA),
            std::make_pair(456, MONTENEGRO),
            std::make_pair(293, BOSNIA),
            std::make_pair(115, SLOVENIA)
    });
    AdjacencyList[24] = croatia;

    Edge slovenia(SLOVENIA,{
            std::make_pair(388, HUNGARY),
            std::make_pair(115, CROATIA),
            std::make_pair(276, AUSTRIA),
            std::make_pair(496, ITALY)
    });
    AdjacencyList[25] = slovenia;

    Edge austria(AUSTRIA,{
            std::make_pair(54, SLOVAKIA),
            std::make_pair(255, CZECHIA),
            std::make_pair(221, HUNGARY),
            std::make_pair(276, SLOVENIA),
            std::make_pair(528, GERMANY),
            std::make_pair(523, LIECHTENSTEIN),
            std::make_pair(685, SWITZERLAND),
            std::make_pair(766, ITALY)
    });
    AdjacencyList[26] = austria;

    Edge germany(GERMANY,{
            std::make_pair(528, POLAND),
            std::make_pair(280, CZECHIA),
            std::make_pair(528, AUSTRIA),
            std::make_pair(355, DENMARK),
            std::make_pair(574, NETHERLANDS),
            std::make_pair(646, BELGIUM),
            std::make_pair(602, LUXEMBOURG),
            std::make_pair(750, SWITZERLAND),
            std::make_pair(874, FRANCE)
    });
    AdjacencyList[27] = germany;

    Edge denmark(DENMARK,{
            std::make_pair(355, GERMANY)
    });
    AdjacencyList[28] = denmark;

    Edge netherlands(NETHERLANDS,{
            std::make_pair(574, GERMANY),
            std::make_pair(182, BELGIUM)
    });
    AdjacencyList[29] = netherlands;

    Edge belgium(BELGIUM,{
            std::make_pair(646, GERMANY),
            std::make_pair(182, NETHERLANDS),
            std::make_pair(183, LUXEMBOURG),
            std::make_pair(262, FRANCE)
    });
    AdjacencyList[30] = belgium;

    Edge liechtenstein(LIECHTENSTEIN,{
            std::make_pair(523, AUSTRIA),
            std::make_pair(165, SWITZERLAND)
    });
    AdjacencyList[31] = liechtenstein;


    Edge luxembourg(LUXEMBOURG,{
            std::make_pair(602, GERMANY),
            std::make_pair(183, BELGIUM),
            std::make_pair(288, FRANCE)
    });
    AdjacencyList[32] = luxembourg;

    Edge switzerland(SWITZERLAND,{
            std::make_pair(685, AUSTRIA),
            std::make_pair(750, GERMANY),
            std::make_pair(165, LIECHTENSTEIN),
            std::make_pair(437, FRANCE),
            std::make_pair(695, ITALY)
    });
    AdjacencyList[33] = switzerland;

    Edge france(FRANCE,{
            std::make_pair(874, GERMANY),
            std::make_pair(262, BELGIUM),
            std::make_pair(288, LUXEMBOURG),
            std::make_pair(437, SWITZERLAND),
            std::make_pair(688, MONACO),
            std::make_pair(1108, ITALY),
            std::make_pair(707, ANDORRA),
            std::make_pair(1052, SPAIN)
    });
    AdjacencyList[34] = france;

    Edge monaco(MONACO,{
            std::make_pair(688, FRANCE)
    });
    AdjacencyList[35] =  monaco;

    Edge italy(ITALY,{
            std::make_pair(496, SLOVENIA),
            std::make_pair(766, AUSTRIA),
            std::make_pair(695, SWITZERLAND),
            std::make_pair(1108, FRANCE),
            std::make_pair(225, SANMARINO),
            std::make_pair(0, VATICAN)
    });
    AdjacencyList[36] =  italy;

    Edge sanmarino(SANMARINO,{
            std::make_pair(225, ITALY)
    });
    AdjacencyList[37] =  sanmarino;

    Edge vatican(VATICAN,{
            std::make_pair(0, ITALY)
    });
    AdjacencyList[38] =  vatican;

    Edge andorra(ANDORRA,{
            std::make_pair(707, FRANCE),
            std::make_pair(495, SPAIN)
    });
    AdjacencyList[39] =  andorra;

    Edge spain(SPAIN,{
            std::make_pair(1052, FRANCE),
            std::make_pair(495, ANDORRA),
            std::make_pair(503, PORTUGAL)
    });
    AdjacencyList[40] =  spain;

    Edge portugal(PORTUGAL,{
            std::make_pair(503, SPAIN)
    });
    AdjacencyList[41] =  portugal;

   PrimSpanningTree(AdjacencyList);


  //for closed walk every edge (counts all vertices with odd amount of edges)
  /*
    int counter =0;
    for(int i =0;i<AdjacencyList.size();i++){
        if(AdjacencyList[i].edge.size() % 2 == 1){
       counter++;
       std::cout << EuropeOutput[i] << std::endl;
        }
    }
    std::cout << counter << std::endl;
*/

    //alphabet order for prufer code
    /*
    std::cout  << std::endl;
    std::cout << "countries in alphabet order: " << std::endl;
    std::sort(EuropeOutput.begin(), EuropeOutput.end());
    for(int i=0;i<EuropeOutput.size();i++){
        std::cout << i+1 << "  " << EuropeOutput[i] << std::endl;
    }
     */
}


/*
enum Europe{RUSSIA,UKRAINE,BELARUS,ESTONIA,LATVIA,LITHUANIA,FINLAND,NORWAY,SWEDEN,POLAND,MOLDOVA,SLOVAKIA,ROMANIA,CZECHIA,HUNGARY,SERBIA,BULGARIA,
    MACEDONIA,GREECE,TURKEY,GEORGIA,ALBANIA,MONTENEGRO,BOSNIA,CROATIA,SLOVENIA,AUSTRIA,GERMANY,DENMARK,NETHERLANDS,BELGIUM,LIECHTENSTEIN,
    LUXEMBOURG,SWITZERLAND,FRANCE,MONACO,ITALY,SANMARINO,VATICAN,ANDORRA,SPAIN,PORTUGAL};
*/