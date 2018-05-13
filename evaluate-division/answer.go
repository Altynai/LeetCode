
type Edge struct {
    v int32
    w float64
    nxt int32
}

var n, m int32
var name2id map[string]int32
var head []int32
var edges []Edge
var visited []bool

func setup(equations [][]string, values []float64) {
    m, n = 0, 0
    name2id = map[string]int32{}
    for i := 0; i < len(values); i++ {
        from, to := equations[i][0], equations[i][1]
        setName(from)
        setName(to)
    }
    size := len(name2id)
    head = []int32{}
    visited = []bool{}
    for i := 0; i < size; i++ {
        head = append(head, -1)
        visited = append(visited, false)
    }
    edges = []Edge{}
    for index, value := range values {
        from, to := equations[index][0], equations[index][1]
        id1 := setName(from)
        id2 := setName(to)
        addEdge(id1, id2, value)
        addEdge(id2, id1, 1.0 / value)
    }
}

func addEdge(u, v int32, w float64) {
    edge := Edge{
        v: v,
        w: w,
        nxt: head[u],
    }
    edges = append(edges, edge)
    head[u] = m
    m++
}

func setName(name string) int32 {
    if id, found := name2id[name]; found {
        return id
    } else {
        id = n
        n++
        name2id[name] = id;
        return id
    }
}

func hasName(name string) bool {
    _, found := name2id[name]
    return found
}

func dfs(u, target int32, product float64) (float64, bool) {
    visited[u] = true
    for i := head[u]; i != -1; i = edges[i].nxt {
        v := edges[i].v
        if v == target {
            return product * edges[i].w, true
        } else if visited[v] {
            continue
        }

        if p, found := dfs(v, target, product * edges[i].w); found {
            return p, found
        }
    }
    return product, false
}

func solve(queries [][]string) []float64 {
    ans := []float64{}
    for _, query := range queries {
        from, to := query[0], query[1]
        if !hasName(from) || !hasName(to) {
            ans = append(ans, -1.0)
        } else if (from == to) {
            ans = append(ans, 1.0)
        } else {
            id1, id2 := setName(from), setName(to)
            for i := 0; i < len(visited); i++ {
                visited[i] = false
            }
            if product, found := dfs(id1, id2, 1.0); found {
                ans = append(ans, product)
            } else {
                ans = append(ans, -1.0)
            }
        }
    }
    return ans;
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
    setup(equations, values)
    return solve(queries)
}

