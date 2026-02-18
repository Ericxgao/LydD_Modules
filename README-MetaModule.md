# LydD Modules — MetaModule Port

This repository includes a MetaModule-compatible port of **LydD Modules**.

## Port Summary

- Fork: `https://github.com/Ericxgao/LydD_Modules`
- Target: MetaModule plugin (`.mmplugin`)
- Plugin artifact (after build): `metamodule-plugins/LydD-Modules.mmplugin`

## Included Modules

All 9 modules from `plugin.json` are included:

1. Poppy-Fields (`Poppy-fields`)
2. Mom-and-Dad (`Dadras-Momeni-Chaos`)
3. Simone (`Simone-Chaos`)
4. Torus (`Torus-Osc`)
5. Concierge (`Clock-Long`)
6. Dobbs (`Dobbs-Env`)
7. Ledger (`Ledger-Logic`)
8. Onceler (`The-Onceler`)
9. Shear (`Shear-Comb`)

## What was added for MetaModule

- `CMakeLists.txt` for MetaModule SDK build flow
- `plugin-mm.json` metadata for plugin packaging
- `assets/` directory with converted PNGs from VCV `res/` SVG sources (including alternate panels and component art)

## Compatibility adaptations

To compile against the MetaModule Rack interface without `#ifndef METAMODULE` branching:

- Replaced VCV-specific `PulseGenerator::isHigh()` usage with state derived from `PulseGenerator::process()` in:
  - `src/Concierge.cpp`
  - `src/Dobbs.cpp`
  - `src/Onceler.cpp`
- Reworked code paths that accessed internal SVG shape handles (not exposed by MetaModule’s SVG abstraction) in:
  - `src/Ledger.cpp`
  - `src/Dobbs.cpp`

## Build Instructions

From repository root:

```bash
export PATH=/Users/ericgao/.openclaw/workspace/arm-gnu-toolchain-15.2.rel1/bin:$PATH
mkdir -p build-mm
cd build-mm
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build . -j8
```

Expected output:

- Shared object: `build-mm/LydD-Modules.so`
- Packaged plugin: `metamodule-plugins/LydD-Modules.mmplugin`

## Verification performed

- MetaModule build completes successfully with SDK toolchain.
- `.mmplugin` package created successfully.
- Packaged archive includes:
  - `plugin.json`
  - `plugin-mm.json`
  - `LydD-Modules.so`
  - converted panel/component assets (`*.png`)

## Known limitations / notes

- Two visual effects were adapted due to SVG internal API differences in the MetaModule environment:
  - Ledger glyph light rendering fallback uses `SvgLight` base rendering.
  - Dobbs envelope overlays use a lightweight overlay draw path rather than direct SVG path iteration.
- Functional DSP/module logic is retained; these changes are primarily visual compatibility accommodations.
