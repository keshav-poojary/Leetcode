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
    steps: list[str] = []

    if "set<" in code or "unordered_set" in code or "set " in code:
        steps.append("A set is created to remember values already seen, which gives us constant-time membership checks for duplicates.")
    if "find(" in code or ".count(" in code or "contains(" in code:
        steps.append("The current value is checked against the previously seen values before any new state is recorded.")
    if "insert(" in code or "push_back(" in code or "append(" in code:
        steps.append("If the value is new, it is inserted into the tracking structure so it can be compared later in the scan.")
    if "for (" in code or "for " in code or "while " in code:
        steps.append("The main loop walks through the input one element at a time and applies the decision logic to every position.")
    if "return true" in code.lower() or "return false" in code.lower():
        steps.append("The function returns immediately when a duplicate is found, which keeps the solution efficient and avoids extra work.")
    if "visited" in code.lower() or "seen" in code.lower():
        steps.append("Visited state is marked as soon as a value or node is processed so repeated work is avoided during the traversal.")
    if "dfs" in low or "bfs" in low or "queue" in low:
        steps.append("The traversal helper expands outward from the current node and only continues through valid neighbors that satisfy the movement rule.")
    if "sort(" in low:
        steps.append("Sorting normalizes the structure of the input so adjacent values or intervals can be compared in a predictable order.")
    if "stack" in low or "deque" in low:
        steps.append("The stack or deque preserves the order of pending work so the algorithm can revisit states in the correct sequence.")

    if category_name == "14-graph":
        steps = [
            "The ocean reachability matrices are initialized for the Pacific and Atlantic boundaries before the DFS begins.",
            "Each DFS call expands only to neighbors whose height is greater than or equal to the current cell, which matches the flow rule from the problem statement.",
            "A visited marker is set for each reached cell so the flood-fill does not revisit the same position unnecessarily.",
            "The final output is built from the intersection of cells that can reach both oceans.",
        ]
    elif category_name == "05.binary-search":
        steps = [
            "The search space is defined by the left and right pointer boundaries instead of iterating through every element.",
            "The midpoint is evaluated against the sorted invariant to decide whether the answer lives on the left or right side.",
            "Pointers move toward each other until the valid range collapses to a single answer.",
            "The final pointer position is returned as the correct result.",
        ]
    elif category_name == "12-intervals":
        steps = [
            "The intervals are sorted so the merge logic always compares the current interval against the next valid range.",
            "A running merged interval is updated whenever the current interval overlaps the active boundary.",
            "Non-overlapping intervals are appended to preserve the final sorted output order.",
            "The final merged vector is returned as the result.",
        ]
    elif category_name == "03.sliding-window":
        steps = [
            "The right pointer expands the current window while the constraints remain satisfied.",
            "The left pointer shrinks the window only when the current state violates the condition, restoring a valid window.",
            "The answer is updated each time a better window is found.",
            "The loop finishes with the best valid window recorded in the answer.",
        ]

    if not steps:
        steps = [
            "The implementation reads the data, transforms it into a compact state, and then mutates that state in a way that matches the problem constraints.",
            "Each condition in the code ensures the next action is valid before the solution continues toward the final output.",
        ]
    return steps


def build_mermaid_diagram(category_name: str) -> str:
    diagrams = {
        "01.Arrays": "flowchart TD\n    A[Read input] --> B[Track seen state]\n    B --> C{Value already seen?}\n    C -- Yes --> D[Return true]\n    C -- No --> E[Insert value]\n    E --> F[Continue scan]\n    F --> G{End of array?}\n    G -- No --> B\n    G -- Yes --> H[Return false]",
        "02.Two-Pointers": "flowchart TD\n    A[Initialize left and right] --> B[Compare values or conditions]\n    B --> C{Move toward target?}\n    C -- Yes --> D[Advance pointer]\n    C -- No --> E[Advance other pointer]\n    D --> B\n    E --> B\n    B --> F[Return result]",
        "03.sliding-window": "flowchart TD\n    A[Set left/right pointers] --> B[Expand right]\n    B --> C{Window valid?}\n    C -- Yes --> D[Update answer]\n    C -- No --> E[Shrink left]\n    D --> B\n    E --> B\n    B --> F{End reached?}\n    F -- Yes --> G[Return best window]",
        "04.stack": "flowchart TD\n    A[Read next value] --> B{Need to push or pop?}\n    B -- Push --> C[Push to stack]\n    B -- Pop --> D[Pop while condition holds]\n    C --> E[Continue]\n    D --> E\n    E --> F{End reached?}\n    F -- No --> A\n    F -- Yes --> G[Return stack result]",
        "05.binary-search": "flowchart TD\n    A[Set low and high] --> B[Compute mid]\n    B --> C{Condition holds?}\n    C -- Yes --> D[Move high left]\n    C -- No --> E[Move low right]\n    D --> B\n    E --> B\n    B --> F[Return answer]",
        "06.linked-lists": "flowchart TD\n    A[Handle null and head cases] --> B[Track current and previous]\n    B --> C[Rewire next pointers]\n    C --> D{More nodes left?}\n    D -- Yes --> B\n    D -- No --> E[Return updated head]",
        "07-binary-tree": "flowchart TD\n    A[Visit node] --> B[Recurse/queue into children]\n    B --> C[Combine child results]\n    C --> D{At root?}\n    D -- No --> B\n    D -- Yes --> E[Return final answer]",
        "08-heaps": "flowchart TD\n    A[Push values into heap] --> B[Peek or pop top]\n    B --> C{Is it the needed extreme?}\n    C -- Yes --> D[Update answer]\n    C -- No --> E[Continue processing]\n    D --> E\n    E --> F{Done?}\n    F -- No --> A\n    F -- Yes --> G[Return result]",
        "09-backtracking": "flowchart TD\n    A[Choose a candidate] --> B[Recurse]\n    B --> C{Valid branch?}\n    C -- Yes --> D[Record choice]\n    C -- No --> E[Backtrack]\n    D --> F[Explore next choice]\n    E --> F\n    F --> G{All options done?}\n    G -- No --> A\n    G -- Yes --> H[Return valid solutions]",
        "10.math-geometry": "flowchart TD\n    A[Model data mathematically] --> B[Compute formula or geometry]\n    B --> C{Check constraints?}\n    C -- Yes --> D[Finalize result]\n    C -- No --> E[Adjust edge case]\n    D --> F[Return answer]\n    E --> D",
        "11.bit-manipulation": "flowchart TD\n    A[Convert to bit pattern] --> B[Apply mask or XOR/AND logic]\n    B --> C{Need more bit checks?}\n    C -- Yes --> B\n    C -- No --> D[Return bit-based answer]",
        "12-intervals": "flowchart TD\n    A[Sort intervals] --> B[Compare current with next]\n    B --> C{Overlap?}\n    C -- Yes --> D[Merge ranges]\n    C -- No --> E[Append result]\n    D --> B\n    E --> B\n    B --> F[Return merged intervals]",
        "13-greedy": "flowchart TD\n    A[Choose locally best valid move] --> B[Update state]\n    B --> C{Problem complete?}\n    C -- No --> A\n    C -- Yes --> D[Return greedy solution]",
        "14-graph": "flowchart TD\n    A[Choose start nodes] --> B[Traverse neighbors]\n    B --> C{Visited already?}\n    C -- Yes --> D[Skip]\n    C -- No --> E[Mark visited]\n    D --> F{More nodes?}\n    E --> F\n    F -- Yes --> B\n    F -- No --> G[Check target condition]\n    G --> H[Return valid nodes]",
    }
    return diagrams.get(category_name, "flowchart TD\n    A[Read problem] --> B[Apply selected strategy] --> C[Validate edge cases] --> D[Return answer]")


def compose_problem_readme(category_name: str, folder: Path) -> str:
    title, summary = read_problem_title_and_summary(folder)
    files = [p.name for p in sorted(folder.iterdir()) if p.is_file() and p.suffix.lower().lstrip(".") in {"cpp", "py", "java", "js", "ts", "cs", "go", "rs"}]
    if not files:
        files = ["No implementation file found in this folder yet."]

    trace = derive_solution_trace(category_name, title)
    code_walkthrough = extract_code_walkthrough(folder, category_name)
    category_label = CATEGORY_ALIASES.get(category_name, category_name.replace("-", " ").title())
    problem_name = folder.name
    mermaid = build_mermaid_diagram(category_name)

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
