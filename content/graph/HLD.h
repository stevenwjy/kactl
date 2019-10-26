/**
 * Author: 7 Halim
 * Date: 2019
 * Description: Decomposes a tree into vertex disjoint heavy paths and light
 *  edges such that the path from any leaf to the root contains at most log(n)
 *  light edges. The function of the HLD can be changed by modifying T, LOW and
 *  f. f is assumed to be associative and commutative.
 */
#pragma once

int n, val[MAXN], num[MAXN], cnt = 0;
int sum[MAXN], pc[MAXN], nc[MAXN], hc[MAXN], lv[MAXN];
vector<int> adj[MAXN];

void reorder (int now, int par) {
	sum[now] = 1;
	for (int i = 0; i < SZ(adj[now]); i++) {
		int &nex = adj[now][i];
		if (nex == par) continue;
		lv[nex] = lv[now] + 1;
		reorder(nex, now);
		sum[now] += sum[nex];
		if (sum[nex] > sum[adj[now][0]]) swap(adj[now][0], nex);
	}
}

void create_hld (int now, int par, int head) {
	hc[now] = head; pc[now] = par; 
	nc[now] = ++cnt; num[cnt] = val[now]; 
	bool fi = 1;
	for (auto nex : adj[now]) {
		if (nex == par) continue;
		if (fi) { create_hld(nex, now, head); fi = 0; } 
		else create_hld(nex, now, nex);
	}
}
