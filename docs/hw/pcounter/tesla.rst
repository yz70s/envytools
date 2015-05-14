.. _pcounter-signal-g80:

=================
G80:GF100 signals
=================

.. contents::


Introduction
============

G80 generation cards have the following counter domains:

- G80:

  - 0: host clock
  - 1: core clock A
  - 2: core clock B
  - 3: shader clock
  - 4: memory clock

- G84:GF100 except MCP7x:

  - 0: host clock
  - 1: core clock A
  - 2: core clock B
  - 3: shader clock
  - 4: memory clock
  - 5: core clock C
  - 6: vdec clock
  - 7: core clock D

- MCP7x:

  - 0: host clock
  - 1: core clock A
  - 2: core clock B
  - 3: shader clock
  - 4: core clock C
  - 5: vdec clock
  - 6: core clock D

.. todo:: figure out roughly what stuff goes where

.. todo:: find signals.


Host clock
==========

================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
signal            G80   G84   G86   G92   G94   G96   G98   G200  MCP77 MCP79 GT215 GT216 GT218 MCP89 documentation
================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
HOST_MEM_WR       00    04    04    04    04    04    04    05    ??    ??    1a    1a    1a    ??     [XXX]
PCOUNTER.USER     --    --    --    --    --    --    --    --    --    --    2a-2b 2a-2b 2a-2b 3a-3b  pcounter/intro.txt
???               ??    ??    ??    ??    ??    ??    ??    0a    ??    ??    ??    ??    ??    ??     all PFIFO engines enabled and idle???
???               ??    ??    ??    ??    ??    ??    28    ??    ??    ??    ??    ??    ??    ??    happens once with PFIFO write or PDISPLAY access [not PFIFO read]
???               ??    ??    ??    ??    ??    ??    ??    29    ??    ??    ??    ??    ??    ??    ??? on for 10%
???               ??    ??    ??    ??    ??    ??    ??    2a    ??    ??    ??    ??    ??    ??    ??? on for 10%
???               ??    ??    ??    ??    ??    ??    ??    2b    ??    ??    ??    ??    ??    ??    pcie activity wakeups [long]?!?
???               ??    ??    ??    ??    ??    ??    ??    2c    ??    ??    ??    ??    ??    ??    pcie activity bursts?!?
???               ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    74    ??    ??    MMIO reads?
HOST_MEM_RD       1a    1f    1f    27    2a    2a    2a    2e    ??    ??    96    96    96    ??     [XXX]
???               1c    21    ??    29    ??    2c    ??    30    ??    ??    ??    ??    98    ??     triple MMIO read?
PBUS_PCIE_RD      1d    22    22    2a    2d    2d    2d    31    ??    ??    99    99    99    ??     [XXX]
PTIMER_TIME_B12   27    2c    2c    34    37    37    37    3b    53    53    a3    a3    a3    4a     bus/ptimer.txt
PBUS_PCIE_TRANS   29    2e    2e    36    39    39    39    3d    ??    ??    a5    a5    a5    ??     [XXX]
PBUS_PCIE_WR      2a    2f    2f    37    3a    3a    3a    3e    ??    ??    a6    a6    a6    ??     [XXX]
PCOUNTER.TRAILER  2e-3f 4c-5f 4c-5f 4c-5f 4c-5f 4c-5f 4c-5f 6c-7f 8c-9f 8c-9f ec-ff ec-ff ec-ff 8c-9f  pcounter/intro.txt
================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============


Core clock A
============

========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
signal                    G80   G84   G86   G92   G94   G96   G98   G200  MCP77 MCP79 GT215 GT216 GT218 MCP89 documentation
========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
TPC.GEOM.MUX              10-16 00-06 00-06 00-06 00-06 00-06 00-06 ??    00-06 00-06 00-06 00-06 00-06 00-06
ZCULL.???                 20-25 07-0c 07-0c 07-0c 07-0c 07-0c 07-0c 07-0c ??    ??    07-0c 07-0c 07-0c ??    rasterized_tiles_*[0-5]
TPC.RAST.???              ??    19    19    19    19    19    ??    ??    ??    ??    ??    ??    ??    ??   
TPC.RAST.???              ??    1a    1a    1a    1a    1a    ??    ??    ??    ??    ??    ??    ??    ??   
PREGEOM.???               ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    2f    ??    ??    flag 2?
PREGEOM.???               ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    30    ??    ??    flag 2?
POSTGEOM.???              ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    33    ??    ??    flag 2?
POSTGEOM.???              ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    34    ??    ??    flag 2?
RATTR.???                 ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    37    37    ??    idle?
APLANE.CG                 --    31-33 31-33 31-33 31-33 31-33 31-33 ??    39-3b 39-3b 39-3b 39-3b 39-3b 39-3b
RATTR.CG                  --    37-39 37-39 37-39 37-39 37-39 37-39 ??    43-45 43-45 43-45 43-45 43-45 43-45
ZCULL.???                 ??    ??    4f    4f    4f    4f    4f    ??    ??    ??    ??    ??    ??    ??   
VFETCH.MUX                26-3f 66-7f 66-7f 66-7f 66-7f 66-7f 66-7f 46-5f 46-5f 46-5f 46-5f 46-5f 46-5f 46-5f
TPC.RAST.CG               --    ??    ??    ??    ??    ??    ??    ??    ??    ??    60-62 60-62 60-62 60-62
PCOUNTER.USER             --    --    --    --    --    --    --    --    --    --    69-6a 69-6a 69-6a 69-6a  pcounter/intro.txt
ZCULL.???                 6e    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??   
ZCULL.???                 ??    ??    ??    ??    ??    ??    ??    ??    ??    75    ??    ??    ??    ??   
ZCULL.???                 ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    77    ??    ??    idle?
APLANE.CG_IFACE_DISABLE   73    --    --    --    --    --    --    --    --    --    --    --    --    --
VATTR.???                 77-7b ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??
VATTR.???                 ??    57    ??    57    57    57    57    ??    7d    ??    ??    7f    7f    ??
VATTR.???                 ??    59    ??    59    59    59    59    ??    7f    ??    ??    81    81    ??
VATTR.???                 7c    5c    5c    5c    5c    5c    5c    82    ??    ??    84    84    84    ??    geom_primitive_out_count
VATTR.???                 7d    5d    5d    5d    5d    5d    5d    83    ??    ??    85    85    85    ??    geom_vertex_out_count
VATTR.CG_IFACE_DISABLE    7e    --    --    --    --    --    --    --    --    --    --    --    --    --
STRMOUT.???               7f    5e    5e    5e    5e    5e    5e    84    ??    ??    86    86    86    ??    stream_out_busy[0]
STRMOUT.???               80    5f    5f    5f    5f    5f    5f    85    ??    ??    87    87    87    ??    stream_out_busy[1]
STRMOUT.???               81    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??
STRMOUT.???               ??    ??    ??    ??    ??    ??    ??    ??    85    ??    ??    ??    ??    ??   
CLIPID.???                ??    ??    ??    ??    ??    ??    ??    ??    ??    8a    ??    8c    8c    ??   
CLIPID.???                ??    ??    ??    ??    ??    ??    ??    ??    ??    8c    ??    8e    8e    ??   
RMASK.???                 ??    ??    ??    ??    ??    ??    ??    ??    8e    ??    ??    ??    ??    ??   
STRMOUT.CG_IFACE_DISABLE  82    --    --    --    --    --    --    --    --    --    --    --    --    --   
TPC.GEOM.???              8d    85    85    85    85    85    85    ??    ??    91    93    93    93    93   
TPC.GEOM.???              8f    87    87    87    87    87    87    ??    ??    93    95    95    95    95   
TPC.GEOM.???              91    89    89    89    89    89    89    ??    ??    95    97    97    97    97   
TPC.GEOM.???              93    8b    8b    8b    8b    8b    8b    ??    ??    97    99    99    99    99   
TPC.GEOM.???              ??    ??    ??    ??    ??    ??    ??    ??    91    ??    ??    ??    ??    ??   
TPC.GEOM.???              ??    ??    ??    ??    ??    ??    ??    ??    93    ??    ??    ??    ??    ??   
TPC.GEOM.???              ??    ??    ??    ??    ??    ??    ??    ??    95    ??    ??    ??    ??    ??   
RATTR.CG_IFACE_DISABLE    95    --    --    --    --    --    --    --    --    --    --    --    --    --   
RATTR.???                 96    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??   
RATTR.???                 97    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??   
RATTR.???                 98    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??   
RATTR.???                 99    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??   
RATTR.???                 ??    8d    8d    8d    8d    8d    8d    ??    97    ??    ??    ??    ??    ??   
TPC.RAST.???              9b    92    92    92    92    92    92    ??    9c    9e    a0    a0    a0    a0   
TPC.RAST.???              9d    94    94    94    94    94    94    ??    9e    a0    a2    a2    a2    a2   
ENG2D.???                 ??    ??    9b    9b    9b    9b    9b    ??    ??    a7    ??    a9    ??    ??   
ENG2D.???                 ??    ??    9d    9d    9d    9d    9d    ??    ??    a9    ??    ab    ??    ??   
ENG2D.CG_IFACE_DISABLE    a7    --    --    --    --    --    --    --    --    --    --    --    --    --   
???                       ae    a4    a4    a4    a4    a4    a4    b0    ??    ??    b2    b2    b2    ??    setup_primitive_culled_count
VCLIP.???                 b8    ae    ??    ae    ae    ae    ae    ??    b8    ba    ??    bc    bc    ??
VCLIP.???                 ba    b0    ??    b0    b0    b0    b0    ??    ba    bc    ??    be    be    ??
VCLIP.CG_IFACE_DISABLE    bb    --    --    --    --    --    --    --    --    --    --    --    --    --
DISPATCH.???              ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ca    ??    ??    idle?
PGRAPH.IDLE               c8    bd    bd    bd    bd    bd    bd    c9    ??    c9    cb    cb    cb    ??    graph/g80-pgraph.txt
PGRAPH.INTR               ca    bf    bf    bf    bf    bf    bf    cb    ??    cb    cd    cd    cd    ??    graph/g80-pgraph.txt
CTXCTL.USER               d2-d5 c7-ca c7-ca c7-ca c7-ca c7-ca c7-ca d3-d6 d1-d4 d3-d6 d5-d8 d5-d8 d5-d8 d5-d8 graph/g80-ctxctl.txt
TRAST.???                 dc    d2    d2    d2    d2    d2    d2    de    ??    ??    e0    e0    e0    ??    setup_primitive_count
TRAST.???                 dd    d3    d3    d3    d3    d3    d3    df    ??    ??    e1    e1    e1    ??    setup_point_count[0]
TRAST.???                 de    d4    d4    d4    d4    d4    d4    e0    ??    ??    e2    e2    e2    ??    setup_line_count[0]
TRAST.???                 df    d5    d5    d5    d5    d5    d5    e1    ??    ??    e3    e3    e3    ??    setup_triangle_count[0]
TRAST.???                 e2    d8    d8    d8    d8    d8    d8    e4    ??    ??    e6    e6    e6    ??    setup_*_count[1]
TRAST.???                 e3    d9    d9    d9    d9    d9    d9    e5    e3    e5    e7    e7    e7    ??    setup_*_count[2]
TRAST.???                 e5    db    db    db    db    db    db    ??    e5    e7    ??    e9    e9    ??
TRAST.CG_IFACE_DISABLE    e6    --    --    --    --    --    --    --    --    --    --    --    --    --
PCOUNTER.TRAILER          ee-ff ec-ff ec-ff ec-ff ec-ff ec-ff ec-ff ec-ff ec-ff ec-ff ec-ff ec-ff ec-ff ec-ff pcounter/intro.txt
========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============


Core clock B
============

========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
signal                    G80   G84   G86   G92   G94   G96   G98   G200  MCP77 MCP79 GT215 GT216 GT218 MCP89 documentation
========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
PROP.MUX                  00-07 00-07 00-07 00-07 00-07 00-07 00-07 00-07 00-07 00-07 00-07 00-07 00-07 00-07
PVPE.???                  3a    ??    ??    ??    ??    ??    --    ??    --    --    --    --    --    --   
CCACHE.???                ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    2a    ??    ??    idle?
CCACHE.???                ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    2c    ??    ??    idle?
TEX.???                   40    1a    1a    1a    1a    1a    1a    32    ??    ??    3a    3a    3a    ??    tex_cache_miss
TEX.???                   41    1b    1b    1b    1b    1b    1b    33    ??    ??    3b    3b    3b    ??    tex_cache_hit
TEX.???                   42    1c    1c    1c    1c    1c    1c    34    ??    ??    3c    3c    3c    ??    texture_waits_for_fb
VATTR.???                 ??    ??    ??    ??    ??    ??    ??    ??    ??    3c    ??    49    ??    ??   
VATTR.???                 ??    ??    ??    ??    ??    ??    ??    ??    ??    3e    ??    4b    ??    ??   
STRMOUT.???               ??    ??    ??    ??    ??    ??    ??    ??    ??    46    ??    4e    ??    ??   
STRMOUT.???               ??    ??    ??    ??    ??    ??    ??    ??    ??    48    ??    50    ??    ??   
CBAR.MUX0                 4a-4d 24-27 24-27 24-27 24-27 24-27 24-27 ??    49-4c 49-4c 51-54 51-54 51-54 51-54
CBAR.MUX1                 4e-51 28-2b 28-2b 28-2b 28-2b 28-2b 28-2b ??    4d-50 4d-50 55-58 55-58 55-58 55-58
CROP.MUX                  52-55 30-33 30-33 30-33 30-33 30-33 30-33 55-58 55-58 55-58 64-67 64-67 64-67 64-67
ENG2D.???                 ??    ??    ??    36-37 36-37 36-37 ??    ??    ??    ??    ??    ??    ??    ??
ZBAR.MUX                  56-59 38-3b 38-3b 38-3b 38-3b 38-3b 38-3b ??    68-6b 68-6b 70-73 70-73 70-73 70-73
???                       6d    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    memory access?
???                       5e    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    happens when reading memory through VGA window?
???                       64    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    memory read?
???                       68    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    memory write?
VCLIP.???                 ??    ??    ??    ??    ??    ??    ??    ??    64    ??    ??    6c    ??    ??   
VCLIP.???                 ??    ??    ??    ??    ??    ??    ??    ??    65    ??    ??    6d    ??    ??   
ZROP.MUX                  6c-6f 44-47 44-47 44-47 44-47 44-47 44-47 74-77 74-77 74-77 7c-7f 7c-7f 7c-7f 7c-7f
TEX.???                   70-73 48-4b 48-4b 48-4b 48-4b 48-4b 48-4b 78-7b 78-7b 78-7b 80-83 80-83 80-83 80-83 texture_sample_level[0-3]
PCOUNTER.USER             --    --    --    --    --    --    --    --    --    --    9e-9f 9e-9f 9e-9f 9e-9f  pcounter/intro.txt
???                       80    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    memory access?
PVPE.???                  89-a6 ??    ??    ??    ??    ??    --    ??    --    --    --    --    --    --   
PROP.???                  ab    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??    ??
MMU.CG_IFACE_DISABLE      ac    --    --    --    --    --    --    --    --    --    --    --    --    --
MMU.BIND                  ad    --    --    --    --    --    --    --    --    --    --    --    --    --    [on core clock D on G84:]
PFB.CG_IFACE_DISABLE      b8    --    --    --    --    --    --    --    --    --    --    --    --    --
PFB.WRITE                 c3    --    --    --    --    --    --    --    --    --    --    --    --    --    [on core clock D on G84:]
PFB.READ                  c4    --    --    --    --    --    --    --    --    --    --    --    --    --    [on core clock D on G84:]
PFB.FLUSH                 c5    --    --    --    --    --    --    --    --    --    --    --    --    --    [on core clock D on G84:]
ZCULL.CG                  --    58-5a 58-5a 58-5a 58-5a 58-5a 58-5a ??    5d-5f 5d-5f 5d-5f 5d-5f 5d-5f 5d-5f
VATTR.CG                  --    --    --    --    --    --    --    ??    84-86 84-86 8c-8e 8c-8e 8c-8e 8c-8e [also on core C]
STRMOUT.CG                --    --    --    --    --    --    --    ??    87-89 87-89 8f-91 8f-91 8f-91 8f-91 [also on core C]
CLIPID.CG                 --    --    --    --    --    --    --    ??    8a-8c 8a-8c 92-94 92-94 92-94 92-94
ENG2D.CG                  --    60-62 60-62 60-62 60-62 60-62 60-62 ??    8d-8f 8d-8f 95-97 95-97 95-97 95-97
VCLIP.CG                  --    --    --    --    --    --    --    ??    90-92 90-92 98-9a 98-9a 98-9a 98-9a [also on core C]
RMASK.CG                  --    --    --    --    --    --    --    ??    93-95 93-95 a0-a2 a0-a2 a0-a2 a0-a2
TRAST.CG                  --    63-65 63-65 63-65 63-65 63-65 63-65 ??    96-98 96-98 a3-a5 a3-a5 a3-a5 a3-a5
TEX.CG                    --    66-68 66-68 66-68 66-68 66-68 66-68 ??    99-9b 99-9b a6-a8 a6-a8 a6-a8 a6-a8
TEX.CG_IFACE_DISABLE      dd    --    --    --    --    --    --    --    --    --    --    --    --    --
TEX.UNK6.???              df    7d    7d    7d    7d    7d    75    ??    ad    ad    b7    b7    b7    b7
CCACHE.CG_IFACE_DISABLE   ea    --    --    --    --    --    --    --    --    --    --    --    --    --
PSEC.PM_TRIGGER_ALT       --    --    --    --    --    --    --    --    c4    c4    --    --    --    --    [on core clock C on G98]
PSEC.WRCACHE_FLUSH_ALT    --    --    --    --    --    --    --    --    c5    c5    --    --    --    --    [on core clock C on G98]
PSEC.FALCON               --    --    --    --    --    --    --    --    c6-d9 c6-d9 --    --    --    --    [on core clock C on G98]
PCOUNTER.TRAILER          ee-ff 8c-9f 8c-9f 8c-9f 8c-9f 8c-9f 8c-9f ec-ff ec-ff ec-ff cc-df cc-df cc-df cc-df  pcounter/intro.txt
========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============


Shader clock
============

- 0x00-0x03: MPC GROUP 0
- 0x04-0x07: MPC GROUP 1
- 0x08-0x0b: MPC GROUP 2
- 0x0c-0x0f: MPC GROUP 3
- [XXX]
- 0x13-0x14: PCOUNTER.USER [GT215:]
- 0x2e-0x3f: PCOUNTER.TRAILER [G80]
- 0x2c-0x3f: PCOUNTER.TRAILER [G84:]


Memory clock
============

MCP7x don't have this set. MCP89 does.

========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
signal                    G80   G84   G86   G92   G94   G96   G98   G200  GT215 GT216 GT218 MCP89  documentation
========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
PFB.UNK6.CG_IFACE_DISABLE 1a    --    --    --    --    --    --    --    --    --    --    --
PFB.UNK6.CG               --    14-16 14-16 14-16 14-16 14-16 14-16 ??    1a-1c 1a-1c 1a-1c ??
PCOUNTER,USER             --    --    --    --    --    --    --    --    3b-3c 3b-3c 37-38 6a-6b  pcounter/intro.txt
PCOUNTER.TRAILER          2e-3f 4c-5f 4c-5f 4c-5f 4c-5f 4c-5f 4c-5f 6c-7f 6c-7f 6c-7f 6c-7f ec-ff  pcounter/intro.txt
========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============


Core clock C
============

========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =================
signal                    G84   G86   G92   G94   G96   G98   G200  MCP77 MCP79 GT215 GT216 GT218 MCP89 documentation
========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =================
PBSP.USER                 ??    ??    --    ??    ??    --    00-07 --    --    --    --    --    --    [also on core clock D]
PVP2.USER                 ??    ??    --    ??    ??    --    08-0f --    --    --    --    --    --    [also on core clock D]
VCLIP.???                 20    20    20    20    20    20    ??    ??    ??    ??    ??    ??    ??
VCLIP.???                 21    21    21    21    21    21    ??    ??    ??    ??    ??    ??    ??
VATTR.CG                  24-26 24-26 24-26 24-26 24-26 24-26 ??    --    --    --    --    --    --    [also on core B]
STRMOUT.CG                27-29 27-29 27-29 27-29 27-29 27-29 ??    --    --    --    --    --    --    [also on core B]
VCLIP.CG                  2a-2c 2a-2c 2a-2c 2a-2c 2a-2c 2a-2c ??    --    --    --    --    --    --    [also on core B]
VUC_IDLE                  ??    ??    ??    ??    ??    --    34    --    --    --    --    --    --     vdec/vuc/perf.txt
VUC_SLEEP                 ??    ??    ??    ??    ??    --    36    --    --    --    --    --    --     vdec/vuc/perf.txt
VUC_WATCHDOG              ??    ??    ??    ??    ??    --    38    --    --    --    --    --    --     vdec/vuc/perf.txt
VUC_USER_PULSE            ??    ??    ??    ??    ??    --    39    --    --    --    --    --    --     vdec/vuc/perf.txt
VUC_USER_CONT             ??    ??    ??    ??    ??    --    3a    --    --    --    --    --    --     vdec/vuc/perf.txt
PSEC.PM_TRIGGER_ALT       --    --    --    --    --    37    --    --    --    --    --    --    --    [this and other PSEC stuff on core clock B on MCP*]
PSEC.WRCACHE_FLUSH_ALT    --    --    --    --    --    38    --    --    --    --    --    --    --
PSEC.FALCON               --    --    --    --    --    39-4c --    --    --    --    --    --    --
PCOUNTER.USER             --    --    --    --    --    --    --    --    --    10-11 10-11 10-11 10-11  pcounter/intro.txt
PCOPY.PM_TRIGGER_ALT      --    --    --    --    --    --    --    --    --    1d    1d    1d    1d   
PCOPY.WRCACHE_FLUSH_ALT   --    --    --    --    --    --    --    --    --    1e    1e    1e    1e   
PCOPY.FALCON              --    --    --    --    --    --    --    --    --    1f-32 1f-32 1f-32 1f-32  falcon/perf.txt
PDAEMON.PM_TRIGGER_ALT    --    --    --    --    --    --    --    --    --    3e    3e    3e    3e   
PDAEMON.WRCACHE_FLUSH_ALT --    --    --    --    --    --    --    --    --    3f    3f    3f    3f   
PDAEMON.FALCON            --    --    --    --    --    --    --    --    --    40-53 40-53 40-53 40-53  falcon/perf.txt
PCOUNTER.TRAILER          4c-5f 4c-5f 4c-5f 4c-5f 4c-5f 6c-7f 6c-7f 0c-1f 0c-1f 6c-7f 6c-7f 6c-7f 6c-7f  pcounter/intro.txt
========================= ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =================


Vdec clock (VP2)
================

===================== ===== ===== ===== ===== ===== ===== ===============
signal                G84   G86   G92   G94   G96   G200  documentation
===================== ===== ===== ===== ===== ===== ===== ===============
PVP2_USER_0           ??    ??    00-07 ??    ??    00-07 vdec/vp2/intro.txt
PVP2.CG_IFACE_DISABLE 28    28    28    28    r28   ??    what?
PCOUNTER.TRAILER      ac-bf ac-bf ac-bf ac-bf ac-bf ac-bf pcounter/intro.txt
===================== ===== ===== ===== ===== ===== ===== ===============


Vdec clock (VP3/VP4)
====================

=================== ===== ===== ===== ===== ===== ===== ===== ===============
signal              G98   MCP77 MCP79 GT215 GT216 GT218 MCP89 documentation
=================== ===== ===== ===== ===== ===== ===== ===== ===============
PCOUNTER.USER       --    --    --    10-11 10-11 10-11 10-11  pcounter/intro.txt
PVLD.FALCON         10-23 10-23 10-23 16-29 16-29 16-29 16-29  falcon/perf.txt
PPPP.FALCON         40-53 40-53 40-53 2a-3d 2a-3d 2a-3d 2a-3d  falcon/perf.txt
VUC_IDLE            5d    ??    ??    ??    88    ??    ??     vdec/vuc/perf.txt
VUC_SLEEP           5e    ??    ??    ??    89    ??    ??     vdec/vuc/perf.txt
VUC_WATCHDOG        5f    ??    ??    ??    8a    ??    ??     vdec/vuc/perf.txt
VUC_USER_CONT       60    ??    ??    ??    8b    ??    ??     vdec/vuc/perf.txt
VUC_USER_PULSE      61    ??    ??    ??    8c    ??    ??     vdec/vuc/perf.txt
PPDEC.FALCON        8e-a1 8e-a1 8e-a1 3e-51 3e-51 3e-51 3e-51  falcon/perf.txt
PVCOMP.FALCON       --    --    --    --    --    --    52-65  falcon/perf.txt
PVLD.???            ??    ??    ??    ??    54-58 ??    ??   
PPPP.???            ??    ??    ??    ??    5f-7e ??    ??   
PPDEC.XFRM.???      ??    ??    ??    ??    a0-a4 ??    ??   
PPDEC.UNK580.???    ??    ??    ??    ??    ad-af ??    ??   
PPDEC.UNK680.???    ??    ??    ??    ??    b6    ??    ??   
PVLD.CRYPT.???      ??    ??    ??    ??    c0-c5 ??    ??   
PCOUNTER.TRAILER    ac-bf ac-bf ac-bf cc-df cc-df cc-df ec-ff  pcounter/intro.txt
=================== ===== ===== ===== ===== ===== ===== ===== ===============


Core clock D
============

======================== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
signal                   G84   G86   G92   G94   G96   G98   G200  MCP77 MCP79 GT215 GT216 GT218 MCP89 documentation
======================== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
PBSP.USER                ??    ??    00-07 ??    ??    --    --    --    --    --    --    --    --    [also on core clock C]
PVP2.USER                ??    ??    08-0f ??    ??    --    --    --    --    --    --    --    --    [also on core clock C]
PFB.CG                   10-12 10-12 10-12 10-12 10-12 00-02 ??    00-02 00-02 00-02 00-02 00-02 00-02
???                      ??    ??    ??    ??    ??    07    ??    ??    ??    ??    ??    ??    ??     something related to MAGIC_FLUSH + PFIFO memory read?
MMU.CG                   3a-3c 3a-3c 3a-3c 3a-3c 3a-3c 1d-1f ??    24-26 24-26 1d-1f 1d-1f 1d-1f 30-32
PBSP.CG                  5b-5d 3d-3f 63-65 5b-5d 5b-5d --    ??    --    --    --    --    --    --
???                      ??    ??    ??    ??    ??    22    ??    ??    ??    ??    ??    ??    ??     16 * PFIFO host DMAobj load
???                      ??    ??    ??    ??    ??    23    ??    ??    ??    ??    ??    ??    ??     16 * PFIFO host DMAobj load
???                      ??    ??    ??    ??    ??    24    ??    ??    ??    ??    ??    ??    ??     MAGIC_FLUSH + PFIFO memory read
???                      ??    ??    ??    ??    ??    2c    ??    ??    ??    ??    ??    ??    ??     MAGIC_FLUSH + memory access
???                      ??    ??    ??    ??    ??    2e    ??    ??    ??    ??    ??    ??    ??     MAGIC_FLUSH + memory access
???                      ??    ??    ??    ??    ??    30    ??    ??    ??    ??    ??    ??    ??     MAGIC_FLUSH [misses 1 sometimes?] + memory access
???                      ??    ??    ??    ??    ??    32    ??    ??    ??    ??    ??    ??    ??     MAGIC_FLUSH [misses 1 sometimes?] + memory access
PCOUNTER.USER            --    --    --    --    --    --    --    --    --    4f-50 3e-3f 3e-3f 1e-1f  pcounter/intro.txt
MMU.BIND                 ??    5a    ??    ??    ??    34    ??    32    32    5d    5b    4b    50
PFB_WRITE                ??    6f    ??    ??    ??    4b    75    40    40    7d    7b    65    63     [XXX]
PFB_READ                 ??    70    ??    ??    ??    4c    76    41    41    7e    7c    66    64     [XXX]
PFB_FLUSH                ??    71    ??    ??    ??    4d    77    42    42    7f    7d    67    65     [XXX]
PVLD.PM_TRIGGER_ALT      --    --    --    --    --    65    --    6d    6f    9a    98    85    85
PVLD.WRCACHE_FLUSH_ALT   --    --    --    --    --    66    --    6e    70    9b    99    86    86
PPPP.PM_TRIGGER_ALT      --    --    --    --    --    71    --    79    7b    a7    a5    92    92
PPPP.WRCACHE_FLUSH_ALT   --    --    --    --    --    72    --    7a    7c    a8    a6    93    93
PPDEC.PM_TRIGGER_ALT     --    --    --    --    --    8c    --    94    96    b4    b2    9f    9f
PPDEC.WRCACHE_FLUSH_ALT  --    --    --    --    --    8d    --    95    97    b5    b3    a0    a0
PVCOMP.PM_TRIGGER_ALT    --    --    --    --    --    --    --    --    --    --    --    --    ac
PVCOMP.WRCACHE_FLUSH_ALT --    --    --    --    --    --    --    --    --    --    --    --    ad
IREDIR_STATUS            --    --    --    --    --    --    --    --    --    c6    c4    b1    be     pm/pdaemon.txt
IREDIR_HOST_REQ          --    --    --    --    --    --    --    --    --    c7    c5    b2    bf     pm/pdaemon.txt
IREDIR_TRIGGER_DAEMON    --    --    --    --    --    --    --    --    --    c8    c6    b3    c0     pm/pdaemon.txt
IREDIR_TRIGGER_HOST      --    --    --    --    --    --    --    --    --    c9    c7    b4    c1     pm/pdaemon.txt
IREDIR_PMC               --    --    --    --    --    --    --    --    --    ca    c8    b5    c2     pm/pdaemon.txt
IREDIR_INTR              --    --    --    --    --    --    --    --    --    cb    c9    b6    c3     pm/pdaemon.txt
MMIO_BUSY                --    --    --    --    --    --    --    --    --    cc    ca    b7    c4     pm/pdaemon.txt
MMIO_IDLE                --    --    --    --    --    --    --    --    --    cd    cb    b8    c5     pm/pdaemon.txt
MMIO_DISABLED            --    --    --    --    --    --    --    --    --    ce    cc    b9    c6     pm/pdaemon.txt
TOKEN_ALL_USED           --    --    --    --    --    --    --    --    --    cf    cd    ba    c7     pm/pdaemon.txt
TOKEN_NONE_USED          --    --    --    --    --    --    --    --    --    d0    ce    bb    c8     pm/pdaemon.txt
TOKEN_FREE               --    --    --    --    --    --    --    --    --    d1    cf    bc    c9     pm/pdaemon.txt
TOKEN_ALLOC              --    --    --    --    --    --    --    --    --    d2    d0    bd    ca     pm/pdaemon.txt
FIFO_PUT_0_WRITE         --    --    --    --    --    --    --    --    --    d3    d1    be    cb     pm/pdaemon.txt
FIFO_PUT_1_WRITE         --    --    --    --    --    --    --    --    --    d4    d2    bf    cd     pm/pdaemon.txt
FIFO_PUT_2_WRITE         --    --    --    --    --    --    --    --    --    d5    d3    c0    ce     pm/pdaemon.txt
FIFO_PUT_3_WRITE         --    --    --    --    --    --    --    --    --    d6    d4    c1    cf     pm/pdaemon.txt
INPUT_CHANGE             --    --    --    --    --    --    --    --    --    d7    d5    c2    d0     pm/pdaemon.txt
OUTPUT_2                 --    --    --    --    --    --    --    --    --    d8    d6    c3    d1     pm/pdaemon.txt
INPUT_2                  --    --    --    --    --    --    --    --    --    d9    d7    c4    d2     pm/pdaemon.txt
THERM_ACCESS_BUSY        --    --    --    --    --    --    --    --    --    da    d8    c5    d3     pm/pdaemon.txt
PCOUNTER.TRAILER         ec-ff cc-df ec-ff ec-ff ec-ff ac-bf 8c-9f ac-bf ac-bf ec-ff ec-ff cc-df ec-ff  pcounter/intro.txt
======================== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===============
