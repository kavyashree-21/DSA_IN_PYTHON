class Solution:
    def combinationSum(self, candidates, target):
        result = []
        current = []

        def solve(index, target):
            if target == 0:
                result.append(current[:])
                return

            for i in range(index, len(candidates)):
                if candidates[i] > target:
                    continue

                current.append(candidates[i])

                solve(i, target - candidates[i])

                current.pop()

        solve(0, target)

        return result