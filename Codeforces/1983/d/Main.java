import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        t = in.nextInt();
        Task task = new Task();
        for (int i = 0; i < t; i++) {
            task.solve(in, out);
        }
        out.close();
    }

    static class Task {
        private class Fenwick {
            private int n;
            private long[] t;

            public Fenwick(int n) {
                this.n = n + 1;
                this.t = new long[n + 1];
            }

            public void add(int x, long v) {
                for (++x; x < this.n; x += x & -x) {
                    t[x] += v;
                }
            }

            public long sum(int x) {
                long res = 0;
                for (++x; x > 0; x -= x & -x) {
                    res += t[x];
                }
                return res;
            }

            public long rangeSum(int l, int r) {
                return sum(r) - sum(l - 1);
            }
        }

        private boolean cal(int[] a) {
            final int n = a.length;
            long res = 0;
            int[] b = Arrays.stream(a).sorted().distinct().toArray();
            Fenwick fen = new Fenwick(n + 1);
            for (int j : a) {
                int l = lower_bound(b, j);
                res += fen.rangeSum(l, n);
                fen.add(l, 1);
            }
            return res % 2 == 1;
        }

        private static int lower_bound(int[] arr, int x) {
            int p = -1;
            int l = 0, r = arr.length - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (arr[mid] >= x) {
                    p = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return p;
        }

        public void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n], b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            for (int i = 0; i < n; i++) {
                b[i] = in.nextInt();
            }
            int[] sorted_a = Arrays.stream(a).sorted().toArray();
            int[] sorted_b = Arrays.stream(b).sorted().toArray();
            if (!Arrays.equals(sorted_a, sorted_b)) {
                out.println("NO");
                return;
            }
            out.println(cal(a) == cal(b) ? "YES" : "NO");
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
