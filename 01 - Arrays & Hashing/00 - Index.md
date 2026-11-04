---
tags: [dsa, index, index/pattern, pattern/arrays-hashing]
status: learning
last_revised: 2026-11-04
---

# 01 · Arrays & Hashing: Index

← [[00 - Master Index|Master Index]]

## In this folder
| What | Where |
|------|-------|
| Notes | [[01 - Arrays & Hashing]] |
| Practice code | `code/<ProblemName>.java` · run `java <ProblemName>.java` from `code/` |
| PDFs (local only, not in git) | [[Arrays_Linear_Scan_Cheat_Sheet.pdf\|Cheat Sheet]] · [[Arrays_Linear_Scan_Revision_Sheet.pdf\|Revision Sheet]] · [[Arrays_Linear_Scan_Detailed_Notes.pdf\|Detailed Notes]] |

## Which technique?
| Signal in the problem | Jump to |
|-----------------------|---------|
| Element appearing > n/2 times, O(1) space | [[01 - Arrays & Hashing#LC 169 · Majority Element · 🟢 Easy\|LC 169 Majority Element]] (Boyer-Moore) |
| Elements appearing > n/3 (or n/k) times | [[01 - Arrays & Hashing#LC 229 · Majority Element II · 🟡 Medium\|LC 229 Majority Element II]] (Boyer-Moore, 2 candidates) |
| Max / min sum of contiguous subarray | [[01 - Arrays & Hashing#LC 53 · Maximum Subarray (Kadane's Algorithm) · 🟡 Medium\|LC 53 Maximum Subarray]] (Kadane) |
| Max product of contiguous subarray (negatives flip sign) | [[01 - Arrays & Hashing#LC 152 · Maximum Product Subarray · 🟡 Medium\|LC 152 Maximum Product Subarray]] (Kadane, max + min) |
| Count / presence / duplicates | [[01 - Arrays & Hashing#Template\|Arrays & Hashing]] (HashMap) |

## Problems
| # | Problem | Technique | Diff | Confidence | Practice file |
|---|---------|-----------|------|-----------|---------------|
| 169 | [[01 - Arrays & Hashing#LC 169 · Majority Element · 🟢 Easy\|Majority Element]] | Boyer-Moore | 🟢 | ⚠️ | `MajorityElement.java` |
| 53 | [[01 - Arrays & Hashing#LC 53 · Maximum Subarray (Kadane's Algorithm) · 🟡 Medium\|Maximum Subarray (Kadane)]] | Kadane | 🟡 | ❌ | `MaximumSubarray.java` |
| 229 | [[01 - Arrays & Hashing#LC 229 · Majority Element II · 🟡 Medium\|Majority Element II]] | Boyer-Moore ×2 | 🟡 | ❌ | `MajorityElementII.java` |
| 152 | [[01 - Arrays & Hashing#LC 152 · Maximum Product Subarray · 🟡 Medium\|Maximum Product Subarray]] | Kadane max+min | 🟡 | ❌ | `MaximumProductSubarray.java` |

**Totals:** 4 problems · ✅ 0 · ⚠️ 1 · ❌ 3
