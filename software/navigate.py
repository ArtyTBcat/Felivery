import osmnx as ox
import pickle
import matplotlib.pyplot as plt
import networkx as nx
import taxicab as tc

save_data = True
place = "Chonburi, Thailand"


class map_data:
    map : None
    def save():
        with open('map.pkl', 'wb') as file:
            pickle.dump(map_data.map, file)
    def load():
        data = None
        with open('map.pkl', 'rb') as file:
            data = pickle.load(file)
        return(data)
    def get():
        map_data.map = ox.graph_from_place(place, network_type="drive")
        # map_data.map = ox.graph_from_point((-33.889606, 151.283306), dist= 3000, network_type='drive')
        map_data.map = ox.add_edge_speeds(map_data.map)
        map_data.map = ox.add_edge_travel_times(map_data.map)
        ox.save_graph_geopackage(map_data.map, filepath="piedmont.gpkg")
        map_data.save()

# map_data.get()
G = map_data.load()


orig = (13.191614, 100.938854)
dest = (13.182623, 100.935021)
route = tc.distance.shortest_path(G, orig, dest)
route_node_atrabute = [G.nodes[i] for i in list(route)[1]]
print(route_node_atrabute)
print(list(route)[1])
road_edges = G.edges[1684271497, 5839010992, 0]['geometry']
print(road_edges)

fig, ax = tc.plot.plot_graph_route(G, route, node_size=30, show=False, close=False, figsize=(10, 10))
padding = 0.01
ax.scatter(orig[1], orig[0], c='lime', s=200, label='orig', marker='x')
ax.scatter(dest[1], dest[0], c='red', s=200, label='dest', marker='x')
ax.set_ylim([min([orig[0], dest[0]])-padding, max([orig[0], dest[0]])+padding])
ax.set_xlim([min([orig[1], dest[1]])-padding, max([orig[1], dest[1]])+padding])
plt.show()

