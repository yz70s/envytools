.. _tesla-trans:

============================
Transcendential instructions
============================

.. contents::


Introduction
============

.. todo:: write me


Preparation: pre
================

.. todo:: write me

::

  presin f32 DST SRC
  preex2 f32 DST SRC

    Preprocesses a float argument for use in subsequent sin/cos or ex2
    operation, respectively.


Reciprocal: rcp
===============

.. todo:: write me

::

  rcp f32 DST SRC

    Computes 1/x.


Reciprocal square root: rsqrt
=============================

.. todo:: write me

::

  rsqrt f32 DST SRC

    Computes 1/sqrt(x).


Base-2 logarithm: lg2
=====================

.. todo:: write me

::

  lg2 f32 DST SRC

    Computes log_2(x).


Sinus/cosinus: sin, cos
=======================

.. todo:: write me

::

  sin f32 DST SRC
  cos f32 DST SRC

    Computes sin(x) or cos(x), needs argument preprocessed by pre.sin.


Base-2 exponential: ex2
=======================

.. todo:: write me

::

  ex2 f32 DST SRC

    Computes 2**x, needs argument preprocessed by pre.ex2.
