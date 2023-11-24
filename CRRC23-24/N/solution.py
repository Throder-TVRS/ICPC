def solve_N():
    n = int(input())
    data = list(input().split())
 
    out = None
 
    for i in range(n):
        if data[i] == '?':
            continue
 
        j = i + 1
        d = int(data[i]) * j
 
        cd = j // 2
        lb = d - cd
        ub = d + cd - (1 if (j % 2 == 0) else 0)
        candidates = set(range(lb, ub + 1, 1))
        if out is None:
            out = candidates
        else:
            out.intersection_update(candidates)
 
    if out is None:
        print(0)
    else:
        print(min(out))


if __name__ == "__main__":
    solve_N()