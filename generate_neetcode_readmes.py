from __future__ import annotations

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
NEETCODE_ROOT = ROOT / "NeetCode-Submissions"

CATEGORY_GUIDES = {
    "01.Arrays": "Use array scanning and counting patterns, keeping track of state while minimizing redundant passes.",
    "02.Two-Pointers": "Use two pointers to traverse from opposite ends or different positions to reduce time complexity.",
    "03.sliding-window": "Maintain a dynamic window and update counts as the window expands or shrinks to stay efficient.",
    "04.stack": "Use stack-based state tracking to handle order-sensitive operations and nested structure problems.",
    "05.binary-search": "Reduce the search space by checking the sorted property and moving the boundary toward the valid answer.",
    "06.linked-lists": "Track pointers carefully and manipulate next relationships while handling edge cases like null heads and cycles.",
    "07-binary-tree": "Traverse the tree with DFS or BFS, carrying information through recursive or iterative state.",
    "08-heaps": "Use priority queues to always access the smallest or largest important value at the correct moment.",
    "09-backtracking": "Explore candidate choices recursively and backtrack once a branch is invalid or complete.",
    "10.math-geometry": "Transform the problem into arithmetic or geometric reasoning and validate edge conditions.",
    "11.bit-manipulation": "Use bit operations to track flags, parity, and efficient integer-level calculations.",
    "12-intervals": "Sort or merge intervals to keep overlapping ranges compact and easy to reason about.",
    "13-greedy": "Choose the locally best valid action first while preserving correctness for the global solution.",
    "14-graph": "Use graph traversal techniques such as DFS, BFS, or union-find to explore connectivity and reachability.",
}

CATEGORY_ALIASES = {
    "01.Arrays": "Arrays",
    "02.Two-Pointers": "Two Pointers",
    "03.sliding-window": "Sliding Window",
    "04.stack": "Stack",
    "05.binary-search": "Binary Search",
    "06.linked-lists": "Linked Lists",
    "07-binary-tree": "Binary Tree",
    "08-heaps": "Heaps",
    "09-backtracking": "Backtracking",
    "10.math-geometry": "Math / Geometry",
    "11.bit-manipulation": "Bit Manipulation",
    "12-intervals": "Intervals",
    "13-greedy": "Greedy",
    "14-graph": "Graph",
}


def normalize_title(problem_name: str) -> str:
    clean = re.sub(r"^\d+[-_.\s]*", "", problem_name)
    clean = clean.replace("-", " ").replace("_", " ")
    clean = re.sub(r"\s+", " ", clean).strip()
    if not clean:
        return "Unsolved Problem"
    return clean.title()


def read_problem_title_and_summary(folder: Path) -> tuple[str, str]:
    problem_file = folder / "problem.md"
    if problem_file.exists():
        text = problem_file.read_text(encoding="utf-8", errors="ignore")
        lines = [line.strip() for line in text.splitlines() if line.strip()]

        title = ""
        for line in lines:
            if re.match(r"^#\s*.+$", line):
                title = line.lstrip("# ").strip()
                break
            if re.match(r"^\d+\.\s+.+$", line):
                title = re.sub(r"^\d+\.\s*", "", line)
                break
            if not line.startswith("Example") and not line.startswith("Input:") and not line.startswith("Output:") and not line.startswith("Constraints:"):
                title = line
                break

        if not title:
            title = normalize_title(folder.name)

        summary_lines: list[str] = []
        seen_title = False
        for line in lines:
            if not seen_title:
                if line == title or re.sub(r"^\d+\.\s*", "", line) == title or line.lstrip("# ").strip() == title:
                    seen_title = True
                    continue
                continue

            if line.startswith("Example") or line.startswith("Input:") or line.startswith("Output:") or line.startswith("Constraints:"):
                break
            if line.startswith("#"):
                continue
            summary_lines.append(line)
            if len(summary_lines) >= 3:
                break

        summary = " ".join(summary_lines).strip()
        if not summary:
            summary = "This problem was solved by translating the requirements into a clean algorithmic pattern and validating edge cases."
        return title, summary

    return normalize_title(folder.name), "This problem was solved by translating the requirements into a clean algorithmic pattern and validating edge cases."


def derive_solution_trace(category_name: str, problem_title: str) -> list[str]:
    if category_name == "14-graph":
        return [
            "Identify the graph structure, whether it is a grid, adjacency list, or connectivity problem.",
            "Choose DFS or BFS to propagate state across reachable nodes.",
            "Mark visited cells or nodes to avoid revisiting and prevent cycles.",
            "Check the target condition at the end of traversal and collect the valid results."
        ]
    if category_name == "12-intervals":
        return [
            "Sort the intervals by start position to normalize the input order.",
            "Merge overlapping or touching intervals using the current boundary state.",
            "Carry forward any remaining non-overlapping pieces after the merge.",
            "Return the final merged structure in the required output format."
        ]
    if category_name == "03.sliding-window":
        return [
            "Convert the problem into a window over the input.",
            "Expand the right boundary while the window remains valid.",
            "Shrink the left boundary only when constraints are violated.",
            "Track the answer as the window updates to keep the logic linear."
        ]
    if category_name == "05.binary-search":
        return [
            "Find the sorted invariant that allows the answer to be narrowed efficiently.",
            "Set the left and right boundaries based on the search condition.",
            "Move only one pointer at a time while preserving the valid answer range.",
            "Return the boundary value once the search condition is fully satisfied."
        ]
    if category_name == "06.linked-lists":
        return [
            "Understand the pointer mutations required by the operation.",
            "Handle head, tail, and null cases explicitly before performing the core algorithm.",
            "Use temporary pointers to preserve the original structure during rewiring.",
            "Verify the final linked list order before returning the result."
        ]
    if category_name == "07-binary-tree":
        return [
            "Choose a traversal order that matches the problem requirement: DFS for depth logic, BFS for level logic.",
            "Pass along the relevant state while visiting each node.",
            "Use recursion or an explicit stack to avoid losing context during traversal.",
            "Merge child results back to the parent to form the final answer."
        ]
    return [
        "Analyze the input and identify the key invariant or constraint the solution must maintain.",
        "Transform the problem into a compact state representation that makes the decision easy to evaluate.",
        "Apply the selected algorithm and update the answer as the scan progresses.",
        "Validate the result against special cases such as empty input, duplicates, boundaries, and single-element cases."
    ]


def extract_code_walkthrough(folder: Path, category_name: str) -> list[str]:
    solution_files = sorted(
        [p for p in folder.iterdir() if p.is_file() and p.suffix.lower().lstrip(".") in {"cpp", "py", "java", "js", "ts", "cs", "go", "rs"}],
        key=lambda p: p.name,
    )
    if not solution_files:
        return [
            "The implementation file is not present in this folder yet, so the walk-through is documented at the algorithmic level.",
            "The core idea is to model the state carefully, process the input once where possible, and validate the edge cases before returning the result.",
        ]

    code = solution_files[0].read_text(encoding="utf-8", errors="ignore")
    low = code.lower()

    if "set<" in code or "unordered_set" in code or "set " in low:
        return [
            "A set is created to remember every value already seen while scanning the input.",
            "On each iteration, the current element is checked against the set before it is inserted.",
            "If the value already exists, the function returns immediately because the duplicate condition is satisfied.",
            "If the scan reaches the end without a duplicate, the function returns false."
        ]

    if "union" in low or "parent" in low or "find(" in low:
        return [
            "Each node starts as its own parent or root in the disjoint-set structure.",
            "For every edge, the code merges the two endpoints into the same connected component with union/find.",
            "The root representative for each node determines whether two vertices are connected.",
            "The final answer is the count of distinct roots left after all unions are processed."
        ]

    if "dfs" in low:
        return [
            "The traversal starts from the relevant source or boundary node and marks it as visited.",
            "Each recursive or iterative DFS step explores all valid neighbors before continuing deeper into the graph.",
            "A visited array prevents cycles and repeated traversal of nodes already processed.",
            "When all reachable nodes are explored, the solution checks whether the final condition is satisfied and returns the result."
        ]

    if "bfs" in low or "queue" in low:
        return [
            "A queue is initialized with the start node or source state to begin traversal.",
            "The algorithm pops the front node, visits it, and explores every neighbor that has not been seen before.",
            "Each newly reached node is marked visited and pushed into the queue for future processing.",
            "The loop continues until the queue is empty, after which the result is determined from the visited set or component count."
        ]

    if "sort(" in low:
        return [
            "The input is sorted or normalized before the main logic so comparisons are consistent and adjacent states are easy to reason about.",
            "The algorithm scans the sorted values or merged intervals and updates the answer as soon as the condition is satisfied.",
            "When the scan reaches the end, the maintained state already contains the correct final result.",
            "The result is returned in the required order and format."
        ]

    if "stack" in low or "deque" in low:
        return [
            "The stack or deque preserves the pending order of operations while the algorithm processes the input.",
            "Values are pushed when their state is discovered, and popped when their condition becomes active.",
            "This structure helps maintain ordering and allows delayed decisions while traversal continues.",
            "Once the stack is fully processed, the final answer is returned from the accumulated state."
        ]

    if "map" in low or "unordered_map" in low:
        return [
            "A hash map stores counts, indices, or state information keyed by the processed value.",
            "As the scan continues, the map reveals whether a value has already appeared or if a state must be updated.",
            "The current element is compared against the map to decide whether the operation should continue or terminate.",
            "The final result is computed from the map state after the full pass is complete."
        ]

    return [
        "The implementation reads the input and transforms it into a compact state that matches the constraints of the problem.",
        "The main loop checks the current item or node against the required condition before updating the answer.",
        "Each branch and guard keeps the algorithm safe for edge cases and prevents redundant work.",
        "After the scan completes, the collected state is returned as the final answer."
    ]


def build_mermaid_diagram(folder: Path, category_name: str) -> str:
    solution_files = sorted(
        [p for p in folder.iterdir() if p.is_file() and p.suffix.lower().lstrip(".") in {"cpp", "py", "java", "js", "ts", "cs", "go", "rs"}],
        key=lambda p: p.name,
    )
    if not solution_files:
        return "flowchart TD\n    A[Read problem] --> B[Apply selected strategy] --> C[Validate edge cases] --> D[Return answer]"

    code = solution_files[0].read_text(encoding="utf-8", errors="ignore")
    low = code.lower()

    if "set<" in code or "unordered_set" in code or "set " in low:
        return "flowchart TD\n    A[Create empty set] --> B[i = 0]\n    B --> C{ i < nums.size? }\n    C -- Yes --> D{ nums[i] in set? }\n    D -- Yes --> E[Return true]\n    D -- No --> F[Insert nums[i] into set]\n    F --> G[i = i + 1]\n    G --> C\n    C -- No --> H[Return false]"

    if "union" in low or "parent" in low or "find(" in low:
        return "flowchart TD\n    A[Initialize parent/root for each node] --> B[For each edge, call union]\n    B --> C{Same root?}\n    C -- No --> D[Merge components]\n    C -- Yes --> E[Skip duplicate connection]\n    D --> F{All edges processed?}\n    E --> F\n    F -- No --> B\n    F -- Yes --> G[Count number of distinct roots]\n    G --> H[Return connected component count]"

    if "dfs" in low:
        return "flowchart TD\n    A[Start from source node] --> B[Mark node visited]\n    B --> C[Iterate over neighbors]\n    C --> D{Neighbor visited?}\n    D -- No --> E[Visit neighbor]\n    D -- Yes --> F[Skip neighbor]\n    E --> G{More neighbors?}\n    F --> G\n    G -- Yes --> C\n    G -- No --> H[Check final condition]\n    H --> I[Return result]"

    if "bfs" in low or "queue" in low:
        return "flowchart TD\n    A[Initialize queue with start node] --> B[Pop front node]\n    B --> C[Visit neighbors]\n    C --> D{Neighbor unvisited?}\n    D -- Yes --> E[Mark visited and push]\n    D -- No --> F[Ignore neighbor]\n    E --> G{Queue not empty?}\n    F --> G\n    G -- Yes --> B\n    G -- No --> H[Return traversal result]"

    if "sort(" in low:
        return "flowchart TD\n    A[Sort values or intervals] --> B[Scan current item]\n    B --> C{Condition holds?}\n    C -- Yes --> D[Update answer]\n    C -- No --> E[Move ahead]\n    D --> F{Reached end?}\n    E --> F\n    F -- No --> B\n    F -- Yes --> G[Return final answer]"

    if "stack" in low or "deque" in low:
        return "flowchart TD\n    A[Read next value] --> B{Need to push or pop?}\n    B -- Push --> C[Push to stack]\n    B -- Pop --> D[Pop while condition holds]\n    C --> E[Continue scanning]\n    D --> E\n    E --> F{End reached?}\n    F -- No --> A\n    F -- Yes --> G[Return stack-driven result]"

    if "map" in low or "unordered_map" in low:
        return "flowchart TD\n    A[Create map for counts or state] --> B[Scan each element]\n    B --> C{Key seen before?}\n    C -- Yes --> D[Update or compare]\n    C -- No --> E[Insert key]\n    D --> F{More elements?}\n    E --> F\n    F -- Yes --> B\n    F -- No --> G[Return computed result]"

    if "while" in low or "for" in low:
        return "flowchart TD\n    A[Initialize state] --> B[Loop over input]\n    B --> C{Check current condition}\n    C -- True --> D[Update answer or state]\n    C -- False --> E[Skip or continue]\n    D --> F{End loop?}\n    E --> F\n    F -- No --> B\n    F -- Yes --> G[Return final answer]"

    return "flowchart TD\n    A[Read input] --> B[Transform to working state] --> C[Apply logic on current item] --> D{Condition holds?}\n    D -- Yes --> E[Update answer] --> F{Done?}\n    D -- No --> F\n    F -- No --> C\n    F -- Yes --> G[Return final result]"


def compose_problem_readme(category_name: str, folder: Path) -> str:
    title, summary = read_problem_title_and_summary(folder)
    files = [p.name for p in sorted(folder.iterdir()) if p.is_file() and p.suffix.lower().lstrip(".") in {"cpp", "py", "java", "js", "ts", "cs", "go", "rs"}]
    if not files:
        files = ["No implementation file found in this folder yet."]

    trace = derive_solution_trace(category_name, title)
    code_walkthrough = extract_code_walkthrough(folder, category_name)
    category_label = CATEGORY_ALIASES.get(category_name, category_name.replace("-", " ").title())
    problem_name = folder.name
    mermaid = build_mermaid_diagram(folder, category_name)

    return (
        f"# {title}\n\n"
        f"## Category\n- {category_label}\n\n"
        f"## Problem Summary\n{summary}\n\n"
        f"## Files\n- " + "\n- ".join(files) + "\n\n"
        f"## Approach\n{CATEGORY_GUIDES.get(category_name, 'Use the core pattern that matches the input constraints and the target behavior.')}\n\n"
        f"## Solution Trace\n" + "\n".join(f"{i + 1}. {step}" for i, step in enumerate(trace)) + "\n\n"
        f"## Code Trace\n" + "\n".join(f"{i + 1}. `{step}`" for i, step in enumerate(code_walkthrough)) + "\n\n"
        f"## Code Walkthrough\n" + "\n".join(f"- {step}" for step in code_walkthrough) + "\n\n"
        f"## Mermaid Diagram\n```mermaid\n{mermaid}\n```\n\n"
        f"## Algorithm\n1. Read the problem constraints and identify the correct state to track.\n2. Choose the most fitting pattern for the data structure involved.\n3. Process the collection or graph in a single pass where possible.\n4. Maintain the answer and verify correctness against edge cases.\n5. Return the final value or structure after the traversal is complete.\n\n"
        f"## Complexity Analysis\n- Time Complexity: O(n) or O(n log n), depending on the exact operation pattern used in the solution.\n- Space Complexity: O(n) or O(1) auxiliary space, based on the chosen data structure and recursion/stack usage.\n\n"
        f"## Core Intuition\nThe solution reduces the problem to a smaller, trackable state and then uses the correct structural pattern to process the input efficiently. This keeps the implementation both easy to follow and correct for the constraints.\n\n"
        f"## Edge Cases\n- Empty input or single-element input\n- Duplicate values or repeated edges\n- Boundary values and extreme indices\n- Already-sorted or reverse-sorted scenarios\n- Cycles, null nodes, or disconnected components when relevant\n\n"
        f"## Folder\n- {problem_name}\n"
    )


def create_category_readme(category_dir: Path):
    category_name = category_dir.name
    problem_dirs = sorted([p for p in category_dir.iterdir() if p.is_dir()])
    lines = [f"# {CATEGORY_ALIASES.get(category_name, category_name.replace('-', ' ').title())}"]
    lines.append("")
    lines.append("## Solved Problems")
    for folder in problem_dirs:
        title, _ = read_problem_title_and_summary(folder)
        relative = f"{folder.name}/readme.md"
        lines.append(f"- [{title}]({relative})")
    category_dir.joinpath("readme.md").write_text("\n".join(lines) + "\n", encoding="utf-8")


def create_root_readme():
    category_dirs = sorted([p for p in NEETCODE_ROOT.iterdir() if p.is_dir()])
    lines = [
        "# NeetCode Solutions",
        "",
        "This repository contains the solved NeetCode problems I worked through, with each folder documented to explain the approach, reasoning, and the main implementation pattern used.",
        "",
        "## Categories",
        "",
    ]

    for category_dir in category_dirs:
        problem_dirs = [p for p in category_dir.iterdir() if p.is_dir()]
        lines.append(f"### {CATEGORY_ALIASES.get(category_dir.name, category_dir.name.replace('-', ' ').title())} ({len(problem_dirs)})")
        lines.append(f"- [Category Index]({category_dir.name}/readme.md)")
        for folder in problem_dirs[:5]:
            title, _ = read_problem_title_and_summary(folder)
            lines.append(f"  - [{title}]({category_dir.name}/{folder.name}/readme.md)")
        if len(problem_dirs) > 5:
            lines.append(f"  - ... and {len(problem_dirs) - 5} more solved problems")
        lines.append("")

    ROOT.joinpath("readme.md").write_text("\n".join(lines) + "\n", encoding="utf-8")


def main():
    if not NEETCODE_ROOT.exists():
        raise FileNotFoundError(f"Missing NeetCode folder at {NEETCODE_ROOT}")

    for category_dir in sorted([p for p in NEETCODE_ROOT.iterdir() if p.is_dir()]):
        create_category_readme(category_dir)
        for problem_dir in sorted([p for p in category_dir.iterdir() if p.is_dir()]):
            readme_path = problem_dir / "readme.md"
            readme_path.write_text(compose_problem_readme(category_dir.name, problem_dir), encoding="utf-8")

    create_root_readme()
    print("NeetCode README generation complete.")


if __name__ == "__main__":
    main()
