class Solution:
    def canReachInner(self, arr: List[int], currentloc: int, visited: set[int], zerolocs: List[int] ) -> bool:
        if currentloc < 0 or currentloc >= len(arr) or currentloc in visited:
            return False
            
        if currentloc in zerolocs:
            return True

        visited.add(currentloc)
        rightloc = currentloc + arr[currentloc]
        leftloc = currentloc - arr[currentloc] 
        return self.canReachInner(arr, leftloc, visited, zerolocs) or self.canReachInner(arr, rightloc, visited, zerolocs)

    def canReach(self, arr: List[int], start: int) -> bool:
        visited = set()
        zerolocs = [i for i, x in enumerate(arr) if x == 0]
        return self.canReachInner(arr, start, visited, zerolocs)
