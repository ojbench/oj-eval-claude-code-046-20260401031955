# Implementation Notes for Problem 046 - Mercenary

## Solution Overview

This implementation provides a complete C++ class hierarchy for a turn-based battle system with three character types: Fighter, Protector, and Caster.

## Key Implementation Details

### Class Structure
- **Base**: Abstract base class with pure virtual functions
  - Static `aliveNumber` tracks total living characters
  - Protected constructor prevents direct instantiation
  - Virtual destructor properly manages `aliveNumber`
  
- **Fighter, Protector, Caster**: Derived classes implementing battle mechanics

### Type Effectiveness System
- Fighter → Caster: 2x damage
- Caster → Protector: 2x damage  
- Protector → Fighter: 2x damage

### Defense Mechanics
- When defending, characters gain stat bonuses:
  - Fighter: +3 HP, +2 Attack
  - Protector: +7 HP, +1 Attack
  - Caster: +5 HP
- Defending characters take reduced damage: `(attack × multiplier) - defender_attack`
- Attackers take counter damage (except Casters)

### Damage Calculation
- Non-defending target: `health -= attack × multiplier`
- Defending target: `health -= max(0, attack × multiplier - target_attack)`
- Counter damage (non-Caster attackers): `attacker_health -= defender_attack`

## Testing

Local testing with provided sample input produces correct output:
```
Input:
3
Protector Uther 100 2
Caster Giana 50 10
Fighter Malfurion 70 4

Output:
Protector Uther is killed
Caster Giana is killed
13
```

## Files
- `Role.hpp`: Complete implementation
- `test.cpp`: Test harness provided in problem description
- `Makefile`: Compilation instructions
- `.gitignore`: Prevents build artifacts from being committed

## Compilation
```bash
make
```

This produces the `code` executable as required by the OJ system.

## OJ Submission Status

Attempted submission multiple times but encountered persistent API error:
- Error: "unable to create submission" (HTTP 400)
- Problem 1778 shows empty "languages" field, suggesting configuration issue
- Repository is successfully pushed to GitHub and publicly accessible
- All required files are present and compilation succeeds

The implementation is complete and tested locally. The OJ API issue appears to be a platform configuration problem rather than an issue with the code.
