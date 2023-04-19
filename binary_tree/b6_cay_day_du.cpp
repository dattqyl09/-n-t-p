#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
struct node
{
    ll data;
    node *left;
    node *right;
    node(ll x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void makeRoot(node *&root, ll u, ll v, char c)
{
    if (c == 'L')
        root->left = new node(v);
    else
        root->right = new node(v);
}
void insertNode(node *&root, ll u, ll v, char c)
{
    if (root == NULL)
        return;
    if (root->data == u)
    {
        makeRoot(root, u, v, c);
    }
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}
bool check(node *root)
{
    if ((root->left != NULL && root->right == NULL) ||(root->left == NULL && root->right != NULL) )
        return false;
    else
    {
        return (check(root->left) && check(root->right));
        return true;
    }
}
int main()
{
    faster();
    node *root = NULL;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll u, v;
        char c;
        cin >> u >> v >> c;
        if (root == NULL)
        {
            root = new node(u);
            makeRoot(root, u, v, c);
        }
        else
            insertNode(root, u, v, c);
    }
    if (check(root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}