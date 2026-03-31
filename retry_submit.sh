#!/bin/bash
for i in {1..20}; do
  echo "Submission attempt $i at $(date)"
  python3 submit_acmoj/acmoj_client.py submit --problem-id 1778 --git-url https://github.com/ojbench/oj-eval-claude-code-046-20260401031955.git > /tmp/submit_result.txt 2>&1
  cat /tmp/submit_result.txt
  if grep -q '"id"' /tmp/submit_result.txt; then
    echo "SUCCESS! Submission created"
    cat /tmp/submit_result.txt | python3 -m json.tool
    exit 0
  fi
  echo "Failed, waiting 45 seconds..."
  sleep 45
done
echo "All attempts failed"
exit 1
