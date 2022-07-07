w new Exception();
            } catch (Exception e) {
                System.out.println("Less than 1");
            }
        } else {
            System.out.println("Greater than 1");
        }
    }

    public static void main(String args[]) {
        test(0);
        test(1);
    }

}
